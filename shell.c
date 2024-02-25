#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 80 


/**
 * struct bulltin - sdfsdc
 * @command:sdzfsqdfsdfr
 * @fun:true
 */

int main(void) {
    char input[MAX_LINE]; 
    char *args[MAX_LINE/2 + 1]; 
    int should_run = 1; 

    while (should_run) {
        printf("Shell> "); 
        fflush(stdout);

        
        fgets(input, MAX_LINE, stdin);

        
        int arg_count = 0;
        char *token = strtok(input, " \n");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " \n");
        }
        args[arg_count] = NULL; 

        
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        
        pid_t pid = fork();

        if (pid < 0) { 
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { 
            
            if (execvp(args[0], args) == -1) {
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }
        } else { 
            
            wait(NULL);
        }
    }

    return 0;
}

