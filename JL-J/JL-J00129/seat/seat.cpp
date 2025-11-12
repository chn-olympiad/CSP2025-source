#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;
long long a[1000005];
int main(){
    preopen("seat.in","r",stdin);
    preopen("seat.out","w",stdout);
    int n,m,s;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin<<a[i];
    }
    s=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=m*n;i++){
        if(a[i]==s){
            if((i/m+1)%2==1){
                cout<<i/m+1<<i%m;
            }
            if((i/m+1)%2==0){
                cout<<i/m+1<<m+1-i%m;
            }
        }
    }

return 0;
}
