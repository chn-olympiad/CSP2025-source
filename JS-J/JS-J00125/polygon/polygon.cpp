#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int N=5e3+10;
ll n;
ll a[N];
ll ans=0;
vector<ll> dp;
inline void dfs(ll op){
    if(dp.size()>=6){
        return;
    }
    if(dp.size()>=3){
        ll maxt=-1;
        ll cntt=0;
        for(ll i=0;i<dp.size();i++){
            maxt=max(maxt,dp[i]);
            cntt=cntt+dp[i];
            cntt%=M;
        }
        if(maxt*2<cntt){
            ans++;
        }
    }
    for(int i=op;i<=n;i++){
        dp.push_back(i);
        dfs(i+1);
        dp.pop_back();
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    ll maxn=-1;
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        cnt=cnt+a[i];
        cnt%=M;
    }
    if(n==3){
        if(cnt>2*maxn){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
        }
    }
    for(ll i=1;i<=n;i++){
        dfs(i);
    }
    cout<<ans;
    return 0;
}
