#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100


bool compareLines(char line1[], char line2[]) {
    return (strcmp(line1, line2) == 0);
}


int detectAndOptimizeClones(char lines[][MAX_LINE_LENGTH], int numLines, char optimizedLines[][MAX_LINE_LENGTH]) {
    bool isClone[MAX_LINES] = {false};  
    int uniqueLinesCount = 0;

    printf("Clones detected:\n");
    for (int i = 0; i < numLines; ++i) {
        if (!isClone[i]) {  
            strcpy(optimizedLines[uniqueLinesCount], lines[i]);
            uniqueLinesCount++;

            for (int j = i + 1; j < numLines; ++j) {
                if (compareLines(lines[i], lines[j])) {
                    printf("Clone detected between lines %d and %d:\n", i + 1, j + 1);
                    printf("%s\n", lines[i]);
                    isClone[j] = true; 
                }
            }
        }
    }

    return uniqueLinesCount; 
}

int main() {
    char lines[MAX_LINES][MAX_LINE_LENGTH];          
    char optimizedLines[MAX_LINES][MAX_LINE_LENGTH]; 
    int numLines = 0;

    printf("Enter lines of code (press Enter on an empty line to finish):\n");
    
   
    while (numLines < MAX_LINES) {
        if (fgets(lines[numLines], MAX_LINE_LENGTH, stdin) == NULL || lines[numLines][0] == '\n') {
            break;
        }

      
        lines[numLines][strcspn(lines[numLines], "\n")] = '\0';
        numLines++;
    }

    
    int uniqueLinesCount = detectAndOptimizeClones(lines, numLines, optimizedLines);

   
    printf("\nOptimized code (without duplicates):\n");
    for (int i = 0; i < uniqueLinesCount; ++i) {
        printf("%s\n", optimizedLines[i]);
    }

    return 0;
}
