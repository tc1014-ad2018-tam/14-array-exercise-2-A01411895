//Luis Ignacio Acosta Zamora A01411895
/*
 * Write a program to read n number of real values in an array and then shows a menu that let the user:
    * Compute the sum of the given numbers.
    * Compute the average of the given numbers.
    * Display the smallest value of the given numbers and the number of the cell where it is stored.
    * Display the biggest value of the given numbers and the number of the cell where it is stored.
 */

#include <stdio.h>

//Function that finds the sum of the numbers in the array, it returns a specific answere so that
//It can b used with the average function.
double totalSum(double list[], unsigned int n) {
    double totalSum=0.0;

    for (int i = 0; i <n ; ++i) {
        totalSum+=list[i];
    }

    return totalSum;
}

//Functions that states the average number of the numbers of the array.
void average(double sum, unsigned int n) {
    double answer= sum/n;
    printf("The total average of the numbers in the array is %lf.\n\n", answer);
}

//Function that find the min value of an array.
void minValue(double list[], unsigned int n){
    double min= list[0];
    int cell = 0;

    for (int i = 1; i < n ; ++i) {
        if (list[i]<min){
            min=list[i];
            cell= i;
        }
    }
    printf("The min number in the array is %lf, and int located in the %d cell.\n\n", min, cell);
}

//Function that finds the maximum value of the array.
void maxValue(double list[], unsigned int n){
    double max= list[0];
    int cell = 0;

    for (int i = 1; i < n ; ++i) {
        if (list[i]>max){
            max=list[i];
            cell= i;
        }
    }
    printf("The max number in the array is %lf, and int located in the %d cell.\n\n", max, cell);
}

int main() {
    //Variables that are used in the program.
    unsigned int n;
    int option;

   //State the purpose of the program to the user.
    printf("This program will request you to form an array, then it will give you the option to choose to find the "
           "sum, the average, the smallest or biggest value inside the array.\n");

    //Request the array length to the user.
    printf("State the size of the array: \n");
    scanf("%d", &n);

    double list[n];

    //Form the array.
    for (int i = 0; i < n ; ++i) {
        printf("Give me integer number %i: ",i+1);
        scanf("%lf", &list[i]);
    }

    printf("Now, choose what you want to find from the array.\n\n");

    do{
        //Present the menu to the user.
        printf("1. Sum?\n");
        printf("2. Average?\n");
        printf("3. Min Value?\n");
        printf("4. Max Value?\n");
        printf("0. Exit\n");
        printf("Please choose an option: ");
        //Save the option the user give.
        scanf("%d", &option);

        //Analyze the option the user gave and pick the correct option of the code.
        switch(option){
            case 1:
                totalSum(list, n);
                printf("The total sum of numbers in the array is %lf.\n\n", totalSum(list, n));
                break;
            case 2:
                //Using the sum function to find the average way easier.
                average(totalSum(list, n), n);
                break;
            case 3:
                minValue(list, n);
                break;
            case 4:
                maxValue(list,n);
                break;
            case 0:
                printf("Good-bye!");
                break;
            default:
                printf("That's not a valid option! Try again.\n");
                break;
        }

    }while(option != 0);

    return 0;
}