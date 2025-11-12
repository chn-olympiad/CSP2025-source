#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long d[5010];
long long m[5010];
long long lmax=LLONG_MIN;
long long n;
long long fi(long long i){
    for(long long j=1;j<i;j++){
        if(a[j]==a[i])return j;
    }
}
long long df(long long i){
    if(m[i]<=a[i]*2)return 0;
    return d[i-1]*2;
}
long long xf(long long i){
    return d[i]-1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];m[i]=m[i-1]+a[i];
    }
    int k=3;
    while(m[k]<=a[k]*2)k++;
    d[k]=1;
    for(long long i=k+1;i<=n;i++){
        d[i]=d[i-1];
        if(a[i]==lmax){
            d[i]+=d[fi(i)];
        }
        else if(a[i]>lmax){
            lmax=a[i];
            d[i]+=df(i);
        }
        else{
            d[i]+=xf(i);
        }

    }cout<<d[n]%998244353;
    return 0;
}
