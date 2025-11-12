#include <bits/stdc++.h>
#define PI pair<int,int>
using namespace std;
const int N=1e5+11;
int dis[N];
vector<int> g[N];
void dijkstra(int s){
    memset(dis,0x3f3f,sizeof(dis));
    dis[0]=0;
    priority_queue<PI,vector<PI>,greater<>> q;
    q.push({0,s});
    while(!q.empty()){
        auto[d,u]=q.top();
        q.pop();
        if(d!=dis[u]) continue;
        for(auto [v,w]=g[u]){
            if(dis[u]>dis[v]+w){
                dis[u]=dis[v]+w;
                q.push({dis[v]+w,v});
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra(s);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
