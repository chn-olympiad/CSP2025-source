#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
typedef pair<int,int> pii;
vector<pair<int,int>> g[N];
long long dist[N];
int st[N];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({dist[1],1});
    while(q.size()){
        pii t=q.top();
        q.pop();
        int u=t.second;
        if(st[u]==1)continue;
        st[u]=1;
        for(pii edge:g[u]){
            int v=edge.first;
            int w=edge.second;
            if(st[v]==1)continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    cout<<dist[n];
    return 0;
}
