#include<bits/stdc++.h>
using namespace std;/*
int n,k,a[500010],t,sum=0,s=0;
int er(int n){
    int t=1,x=0;
    while(n){
        x=x+n%2*t;
        t*=10;
        n/=2;
        s++;
    }
    return x;
}
int sh(int n){
    int x=0,t=pow(10,s);
    for(int i=s;i>=0;i--){
        if(n/t%10==1) x+=pow(2,i);
        else x+=0;
        t/=10;
    }
    return x;
}*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);/*
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        t=a[i];
        for(int j=i;j<n-1;j++){
            if(t==k){
                sum+=1;
                i=j+1;
                break;
            }
            t=sh(er(t)|er(a[j+1]));
        }
    }
    cout<<sum;*/
    int n;
    cin>>n;
    cout<<n;
    return 0;
}
