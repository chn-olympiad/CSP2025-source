#include<bits/stdc++.h>
using namespace std;
const int N=10e6+5;
int main(){
    int s=0,i=0,n=0;
    char a[N];
    for(int i=0;;i++){
        cin>>a[i];
        if(a[i]==0)
            break;
        n=max(n,i-1);
    }
    sort(a+1,a+n+1);
    for(int i=n-1;i>=0;i--)
        if(a[i]==9||a[i]==8||a[i]==7||a[i]==6||a[i]==5||a[i]==4||a[i]==3||a[i]==2||a[i]==1||a[i]==0)
            cout<<a[i];
    return 0;
}
