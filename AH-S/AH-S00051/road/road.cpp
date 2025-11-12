#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
    int to,cost;
};
int dist[1001001],ans;
bool vis[1001001];
vector<Edge> E[10001];
priority_queue<pair<int,int>> pq;
void Dijkstra(int s){
    for(int i=1;i<=n;i++) dist[i]=INT_MAX/2;
    dist[1]=0;
    int u=s,v,w;
    pq.push({0,u});
    while(pq.size()){
        u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:E[u]){
            v=ed.to,w=ed.cost;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({-w,v});
            }
        }
    }
}
int u,v,w,ai,bi,ci,di,ei;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++)
        cin>>ai>>bi>>ci>>di>>ei;
    Dijkstra(1);
    for(int i=1;i<=n;i++)
        ans+=dist[i];
    cout<<ans;
	return 0;
}
