#include<bits/stdc++.h>
using namespace std;
long long n,fac[5010],a[5010],ans,mod=998244353;
long long fp(long long x,long long y){
    long long ans=1;
    while(y>0){
        if(y&1)ans=x*ans%mod;
        y>>=1,x=x*x%mod;
    }
    return ans%mod;
}
long long C(long long x,long long y){
    return fac[x]*fp(fac[y],mod-2)%mod*fp(fac[x-y],mod-2)%mod;
}
void dfs(long long mx,long long k,long long sm){
    if(mx>n)return;
    if(a[max(mx-1,0ll)]*2<sm&&k>2)ans=(ans+1)%mod;
    for(int i=mx;i<n;i++)dfs(i+1,k+1,sm+a[i]);
}
int main(){
    fac[0]=1;
    for(int i=1;i<5010;i++)fac[i]=fac[i-1]*i%998244353;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(n>20){
        for(int i=3;i<=n;i++)ans=(ans+C(n,i))%mod;
        cout<<ans;
        return 0;
    }
    dfs(0,0,0);
    cout<<ans%mod;
    return 0;
}
