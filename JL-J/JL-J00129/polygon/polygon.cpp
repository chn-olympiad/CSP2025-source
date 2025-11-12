#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;
long long a[5005];
int main(){
    preopen("polygon.in","r",stdin);
    preopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n=3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    int cnt=0;
    if(n=4){
        if(a[1]+a[2]>a[3]){
            cnt++;
        }
        if(a[1]+a[2]>a[4]){
            cnt++;
        }
        if(a[1]+a[3]>a[4]){
            cnt++;
        }
        if(a[3]+a[2]>a[4]){
            cnt++;
        }
        cout<<cnt;
    }
    for(int i=1;i<=n-1;i++){
        cnt+=a[i];
    }
    if(cnt<=a[n]){
        cout<<0;
        return 0;
    }
    int sum=0;
    for(int i=1;i<=n-2;i++){
        int j=n-2;
        sum+=i*j;
        j--;
    }
    cout<<sum;

return 0;
}

