/// Will Serface - COP3502C Lab Assignment 6

#include <stdio.h>
#include <malloc.h>

int search(int numbers[], int low, int high, int value) {
    // Recursive Binary Search Algorithm
    if (high - low <= 1) { // Base Case
        if (numbers[low] == value) return low; // Check if lower index equals value
        if (numbers[high] == value) return high; // Check if higher index equals value
        return -1; // Value is not in numbers
    } else { // Recursive Case
        int middle = (low + high) / 2; // Find midpoint of search
        if (numbers[middle] == value) { // Check if midpoint equals value
            return middle; // Return index where value was found
        } else {
            if (numbers[middle] > value) { // Shift down
                return search(numbers, low, middle, value);
            } else { // Shift up
                return search(numbers, middle, high, value);
            }
        }
    }
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}