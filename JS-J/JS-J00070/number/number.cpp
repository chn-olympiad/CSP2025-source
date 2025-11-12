#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w".stdout);
    string m;
    int a[10]={0};
    long long int p=0;
    cin>>m;
    for(int i=0;i<=m.size()-1;i++){
        int n=m[i];
        if(n>=48&&n<=57){
            a[n-48]+=1;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
