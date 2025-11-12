#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long n,a[5555],sum[5555],cnt,mod=998244353;
bool cmp(int x,int y){
    return x<y;
}
void dfs(long long num,long long Max,long long k,long long l){
    if(k==0)return;
    for(long long i=l-1;i>=1;i--){
        if(num-a[i]>Max && a[i]!=-1){
            cnt++,cnt%=mod;
            dfs(num-a[i],Max,k-1,i);
            cnt%=mod;
        }
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n,cmp);
    for(long long i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(long long i=n;i>=3;i--){
        if(a[i]<sum[i]-a[i]){
            cnt++,cnt%=mod;
            dfs(sum[i]-a[i],a[i],i-3,i);
            cnt%=mod;
        }
    }
    printf("%lld",cnt);
    return 0;
}
