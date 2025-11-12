#include<bits/stdc++.h>
using namespace std;
long long n,mum,d;
int DMG(long long b,long long c,long long a[n]){
    if(a[n-1]){

    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<=n-1-i;j++)
            if(a[j+1]>a[j]){
            d=a[j];
            a[j]=a[j+1];
            a[j+i]=d;
            }
    for(int L=3;L<=n;L++)
        for(int i=0;i<=n-3)
    return 0;
}

