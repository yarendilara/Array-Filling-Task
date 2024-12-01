#include "Std2DArrays.h"
#include <iostream>

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int startValue = 1;

    // Fill diagonals starting from the top row (first row, from right to left)
    for (int col = columns - 1; col >= 0; col--) { // Start from the top-right corner
        int i = 0, j = col;
        while (i < rows && j < columns) {
            arr[i][j] = startValue++;
            i++;
            j++;
        }
    }

    // Continue filling diagonals starting from the leftmost column
    for (int row = 1; row < rows; row++) { // Skip the first row since it's already filled
        int i = row, j = 0;
        while (i < rows && j < columns) {
            arr[i][j] = startValue++;
            i++;
            j++;
        }
    }
}

void printArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
