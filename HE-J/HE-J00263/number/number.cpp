#include<bits/stdc++.h>
using namespace std;
string a;
int numcount[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(numcount,0,10);
    cin>>a;
    for(char k:a){
        int w=k-'0';
        if(0<=w&&w<=9)
            numcount[w]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<numcount[i];j++)
            cout<<i;
    }
    return 0;
}
