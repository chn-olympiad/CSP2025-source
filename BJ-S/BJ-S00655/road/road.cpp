#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
    int w;
    int y;
};
vector<node> g[10005];
int vis[10005];
int dis[10005];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dij(){
    vis[10005]=0;
    while(!q.empty()){
        int ww=q.top().first;
        int yy=q.top().second;
        q.pop();
        if(vis[yy]) continue;
        for(int i=0;i<g[yy].size();i++){
            if(ww+g[yy][i].w<dis[g[yy][i].y]){
                dis[g[yy][i].y]=ww+g[yy][i].w;
                q.push({dis[g[yy][i].y],g[yy][i].y});
            }
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        int w[n+1];
        for(int j=1;j<=n;j++){
            cin>>w[j];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                g[i].push_back({w[i]+w[j],j});
                g[j].push_back({w[i]+w[j],i});
            }
        }

    }
    for(int i=0;i<g[1].size();i++){
        q.push({g[1][i].w,g[1][i].y});
    }
    memset(vis,0,sizeof vis);
    dij();
    int ans;
    for(int i=1;i<=n;i++){
        ans+=dis[i];
    }
    cout<<ans;
    return 0;
}