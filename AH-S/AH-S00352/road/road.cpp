#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<pair<int,int>> g[N];
int n,m,k,a[10];
int dist[10010];
bool st[10010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void dijkstra(int s){
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    q.push({0,s});
    while(q.size()){
        pair<int,int> t=q.top();
        q.pop();
        if(st[t.second]==1) continue;
        else st[t.second]=1;
        for(int i=0;i<g[t.second].size();i++){
            int v=g[t.second][i].first;
            int w=g[t.second][i].second;
            if(v>n){
                if(dist[v]>t.second+w+a[v-n-1]){
                    dist[v]=t.second+w;
                    q.push({dist[v],v});
                }
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
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<k;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++){
            int kk;
            cin>>kk;
            g[n+i+1].push_back({j,kk})
        }
    }
    dijkstra(1);
    for(int i=1;i<=n;i++){
        int qq=max(a[i],qq);
    }
    cout<<qq;
    return 0;
}
