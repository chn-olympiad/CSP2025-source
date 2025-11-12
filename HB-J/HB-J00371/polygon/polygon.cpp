#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010];int n;
const int mod=998244353;
ll ksm(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }return ans;
}
unordered_map<ll,ll> mp[2][5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll mx=a[1];
    for(int i=1;i<=n;++i){
        mx=max(a[i],mx);
    }
    // for(int i=n;i>=1;--i){
    //     suf[i]=suf[i+1]+a[i];
    // }
    if(mx==1){
        cout<<ksm(2ll,n)-1ll-n*1ll-1ll*n*(n-1ll)/2ll<<endl;
        return 0;
    }
    mp[0][0][0]=1;
    for(int i=0;i<n;++i){
        int p=i&1;//mp[p][0][0]=1;
        for(ll j=0;j<=mx;++j){
            mp[p^1][j].clear();
        }
        for(ll j=0;j<=mx;++j){
            for(auto k:mp[p][j]){
                ll x=k.first,y=k.second;
                // cerr<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
                // cerr<<p^1<<' '<<x+a[i]<<'\n';
                // if(x+suf[i+1]<=2ll*j)continue;
                mp[p^1][j][x]+=y;mp[p^1][j][x]%=mod;
                mp[p^1][max(j,a[i+1])][x+a[i+1]]+=y;
                mp[p^1][max(j,a[i+1])][x+a[i+1]]%=mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=mx;++i){
        for(auto j:mp[n&1][i]){
            ll x=j.first,y=j.second;
            if(x>i*2ll){
                ans=(ans+y)%mod;
                // cerr<<i<<"fe"<<x<<' '<<y<<' '<<ans<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}