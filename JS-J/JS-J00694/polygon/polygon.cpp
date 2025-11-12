#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,k;
int a[1000005],dp[1005][1005],s[1000005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<(n+1)*n/2-2;
    return 0;
}