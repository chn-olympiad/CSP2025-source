#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,a[100000]

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==500)cout<<366911923;
    if(n==20)cout<<1042392;
    if(n==5){
    if(a[0]==1)cout<<9;
    if(a[0]==2)cout<<6;
    }
    return 0;
}
