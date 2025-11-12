#include <bits/stdc++.h>
using namespace std;
#define zd long long

string GetBin(int a){
    string b;
    int ctd=0;
    while(a>0){
        b=char(a%2+48)+b;
        a/=2;
        ctd++;
    }
    return b;
}

int main()
{
    ifstream read_f;
    read_f.open("xor.in");
    zd n,k;
    n=10;
    read_f>>n>>k;
    int a[n];
    string b;
    for (int i=0;i<n;i++){
        read_f>>a[i];
        b= (GetBin(a[i]));
    }
    ofstream save_f;
    save_f.open("xor.out");
    save_f<<n-a[n];
    return 0;
}
