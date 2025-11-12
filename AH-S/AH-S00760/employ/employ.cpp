#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=998244353;
ll n,m,f[N],t[N],vis[N],ans=0;
char c;
void dfs(ll cur,ll p){
    if(cur>n){
        if(p<=n-m) ans++;
        return ;
    }
    if(p>n-m) return ;
    for(ll i=1;i<=n;i++){
        if(vis[i]==1) continue;
        vis[i]=1;
        if(p<t[i]&&f[i]) dfs(cur+1,p);
        else dfs(cur+1,p+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ1.in","r",stdin);
    freopen("employ1.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>c;
        f[i]=c-48;
    }
    for(ll i=1;i<=n;i++) cin>>t[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}
