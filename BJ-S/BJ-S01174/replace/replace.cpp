

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int _maxiQ = 0;

int main () {

    ifstream inFile("replace.in");
    ofstream outFile("replace.out");

    inFile >> _maxi >> _maxiQ;

    for (int i = 0; i < _maxiQ; i++) {
        outFile << "0\n";
    }

    outFile.close();
    inFile.close();

    return 0;
}
