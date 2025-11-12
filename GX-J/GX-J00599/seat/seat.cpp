#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;
int a[110],b[1][110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int c=n*m;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    int r=a[1];
    for(int i=1;i<c;i++){
        for(int j=i+1;j<=c;j++){
            if(a[i]<a[j]){
                int x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
        }
    }
    if(n==1){
    {
        for(int i=1;i<=m;i++){
            if(a[i]==r){
                cout<<"1"<<" "<<i;
            }
        }
    }
    if(n>1&&m==1){
        for(int i=1;i<=n;i++){
            if(a[i]==r){
                cout<<i<<" "<<"1";
            }
        }
    }
    return 0;
}
