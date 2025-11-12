#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("polygon.in",ios::in);
    ofstream fout("polygon.out",ios::out);

    int n,sum=0,maxv=0;fin>>n;
    for(int i=0;i<n;i++){
        int t;fin>>t;
        sum = sum+t;
        maxv = max(maxv,t);
    }

    if(sum>maxv*2 && n==3) fout<<"1";
    else fout<<"0";
    return 0;
}
