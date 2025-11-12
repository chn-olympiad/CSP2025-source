#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned int seed;
    cin>>seed;
    mt19937 rd(seed);
    
    ofstream fout("seed.txt");
    fout<<rd();
}