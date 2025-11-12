#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to,w;
};
int n,m,k;
vector<edge> g[10005];
queue<int> q;
int dis[10005],vis[10005];
int prim(){
    memset(dis,0x3f,sizeof(dis));
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int h=q.front();
        q.pop();
        for(int i=0;i<g[h].size();i++){
            edge e=g[h][i];
            if(vis[h]==false&&dis[e.to]>g[h][i].w){
                dis[e.to]=g[h][i].w;
                q.push(e.to);
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=dis[i];
        //cout<<dis[i]<<" ";
    }
    return sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,we;i<=m;i++){
        cin>>u>>v>>we;
        g[u].push_back({v,we});
        g[v].push_back({u,we});
    }
    if(k==0){//1~4
        cout<<prim();
    }
    return 0;
}
