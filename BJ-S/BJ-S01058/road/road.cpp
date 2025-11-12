#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
struct node{
    int v,w;
    friend bool operator <(const node &A,const node &B){
        return A.w>B.w;
    }
};
vector<node> G[N];
int dis[N];
int n,m,k;
bool vis[N];
long long ans=0;
void dij(int st){
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    priority_queue<node> q;
    q.push({st,dis[st]});
    while(!q.empty()){
        node cur=q.top();
        q.pop();
        int u=cur.v;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto e:G[u]){
            int v=e.v,w=e.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
bool dfs(int u,int f){
    vis[u]=1;
    bool x;
    bool flag=0,k=0;
    for(auto e:G[u]){
        int v=e.v,w=e.w;
        if(v==f || vis[v]) continue;
        if(dis[v]==dis[u]+w){
            flag=1;
            x=dfs(v,u);
            ans+=w*x;
            k+=x;
        }
    }
    if(!flag){
        if(u<=n) return 1;
        return 0;
    }
    else return k;
}
int c[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>x;
            G[n+i].push_back({j,c[i]+x});
            G[j].push_back({n+i,c[i]+x});
        }
    }
    dij(1);
        memset(vis,0,sizeof vis);
        ans=0;
        dfs(1,1);
    cout<<ans<<endl;
    return 0;
}
