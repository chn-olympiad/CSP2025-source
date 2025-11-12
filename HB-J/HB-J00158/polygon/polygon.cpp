#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,a[5005],b[25],ans,p[5005];
void dfs(int k){
    if(k==n+1){
        ll res=0,maxn=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(b[i]) maxn=max(maxn,a[i]),res+=a[i],cnt++;
        }
        if(cnt<3) return;
        if(res>2*maxn) ans++;
        return;
    }
    b[k]=1;
    dfs(k+1);
    b[k]=0;
    b[k]=0;
    dfs(k+1);
    b[k]=0;
}
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll cal(int x,int y){
    return p[x]*ksm(p[x-y],mod-2)%mod*ksm(p[y],mod-2)%mod;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        dfs(1);
    }
    else{
        p[0]=1;
        for(int i=1;i<=n;i++) p[i]=p[i]*p[i-1]%mod;
        for(int i=3;i<=n;i++){
            ans+=cal(n,i);
        }
    }
    cout<<ans;
    return 0;
}