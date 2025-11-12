#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
struct node{
    ll w,v;
    //bool operator<(node y){ return w>y.w; }
};
vector<node> e[N];
ll c[20],a[20][N],dis[N];
bool vis[N];
bool operator<(node x,node y){ return x.w>y.w; }
/*bool cmp(node x,node y){
     return x.w>y.w;
}*/
priority_queue<node,vector<node>> q;
int n,m,k;
ll ans=1e15+5;
void dfs(int s,ll sum){
    if(s==k+1){
        memset(dis,1e15+5,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[1]=0;
        for(auto ed:e[1]){
            q.push(ed);
        }
        while(!q.empty()){
            node ed=q.top();
            q.pop();
            ll v=ed.v,w=ed.w;
            if(vis[v]) continue;
            vis[v]=1;
            sum+=w;
            for(auto edd:e[v]){
                ll ww=edd.w,vv=edd.v;
                dis[vv]=min(dis[vv],dis[v]+ww);
            }
        }
        ans=min(ans,sum);
        return ;
    }

    dfs(s+1,sum);
    for(int i=1;i<=n;i++){
        e[1].push_back({a[s][i],i});
    }
    dfs(s+1,sum+c[s]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({w,v});
        e[v].push_back({w,u});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
