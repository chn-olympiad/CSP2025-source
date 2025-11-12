#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll db=1;
const ll inf=1e18;
void solve(ll n,ll m,vector<char>&h,vector<ll>&a){
    ll ans=0;
    vector<ll>vis(n+1);
    function<void(ll,ll)> dfs=[&](ll w,ll c){
        if(w>n){
            if(n-c>=m)ans++;
            return;
        }
        for(ll i=1;i<=n;i++){
            if(vis[i])continue;
            vis[i]=1;
            ll cc=c;
            if(c>=a[i])cc++;
            else if(h[w]=='0')cc++;
            dfs(w+1,cc);
            vis[i]=0;
        }
    };dfs(1,0);
    cout<<ans<<"\n";
}
int main(){
    if(db&1)freopen("employ.in","r",stdin);
    if(db&1)freopen("employ.out","w",stdout);
    ll n,m;cin>>n>>m;
    vector<char>h(n+1);
    for(ll i=1;i<=n;i++)cin>>h[i];
    vector<ll>a(n+1);
    for(ll i=1;i<=n;i++)cin>>a[i];
    solve(n,m,h,a);
    return 0;
}
