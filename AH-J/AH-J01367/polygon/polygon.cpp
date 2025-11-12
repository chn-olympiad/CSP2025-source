#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,mod=998244353;
int n,a[maxn],sum[maxn];
ll ans;
ll solve(int p){
    int as=1,a=2;
    while(p){
        if(p&1){
            as=(as*a)%mod;
        }
        a=(a*a)%mod;
        p>>=1;
    }
    return as;
}
void dfs(int now,int nsum,int mx){
    if(sum[now]+nsum<=mx){
        return;
    }
    if(now==0){
        return;
    }
    dfs(now-1,nsum,mx);
    if(a[now]+nsum>mx){
        ans+=solve(now-1);
        ans%=mod;
    }
    else{
        dfs(now-1,nsum+a[now],mx);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=3;i<=n;++i){
        dfs(i-1,0,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}