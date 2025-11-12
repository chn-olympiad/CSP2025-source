#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int total,want,a[500];
int main(){
    ifstream infile;
    ofstream outfile;
    infile.open("employ.in");
    outfile.open("");
    string status;
    infile >> total >> want >> status;
    for(int g = 0;g<total;g++){
        infile >> a[g];
    }
    int ans = 0;
    return 0;
}