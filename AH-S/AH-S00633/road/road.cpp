#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+10,M=1e6+10,INF=0xfffffff;
struct Thing{
    ll v,w;
};
vector<Thing> G[M];
ll n,m,k,ans=INF;
bool vis[N];
void dfs(ll x,ll cnt,ll sum){
    if(sum>ans) return ;
    if(cnt==n){
        ans=min(ans,sum);
        return ;
    }
    for(ll i=0;i<G[x].size();i++){
        ll v=G[x][i].v,w=G[x][i].w;
        if(vis[v]!=true){
            vis[v]=true;
            dfs(v,cnt+1,sum+w);
            vis[v]=false;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1,u,v,w;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs(1,1,0);
    printf("%lld",ans);
    return 0;
}
