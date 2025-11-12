#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
const int inf=0x3f3f3f3f;
vector<pair<int,int> > g[10005];
priority_queue<int,vector<pair<int,int> >,greater<pair<int,int> > > q;
int n,m,k,u,v,w,c[15],a[15][10005],vis[10005],dist[10005];
int prim(){
    int res=0;
    q.push({dist[1],1});
    for(int i=2;i<=n;i++) dist[i]=inf;
    for(int i=1;i<=n;i++){
        int x=-1;
        while(!q.empty()){
            int u=q.top().second,t=q.top().first;
            q.pop();
            if(vis[u]) continue;
            x=u;
            res+=t;
            break;
        }
        if(x==-1) break;
        vis[x]=1;
        for(int j=0;j<g[x].size();j++){
            int v=g[x][j].first,w=g[x][j].second;
            if(dist[v]>dist[x]+w){
                dist[v]=dist[x]+w;
                q.push({w,v});
            }
        }
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    }
    printf("%d",prim());
    return 0;
}
