#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
ll ans,hzh[5002];
int n,a[5002],mxl;
bool F=1;
ll fpow(ll x,ll y){
    ll t=x,res=1;
    while(y){
        if(y&1) res=(res*t)%mod;
        t=(t*t)%mod;
        y>>=1;
    }
    return res;
}
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x,int need){
    if(x==n+1){
        ans+=(need<0);
        ans%=mod;
        return;
    }
    if(need>=hzh[x]) return;
    dfs(x+1,need-a[x]);
    dfs(x+1,need);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        F&=(a[i]==1);
    }
    if(F){
        printf("%lld\n",(fpow(2,n)-1-n-n*(n-1)/2+mod)%mod);
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=n;i>=1;i--){
        hzh[i]=hzh[i+1]+a[i];
        if(!mxl && hzh[i]>a[i-1]){
            mxl=i-1;
        }
    }
    for(int i=1;i<=mxl;i++){
        dfs(i+1,a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
