#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
struct edge{
    int u, v, w;
    bool operator<(const edge& other) const{
        return w>other.w;
    }
};
int p[10005];
bool con[10005];
int find(int node){
    return node==p[node]?node:p[node]=find(p[node]);
}
void solve(){
    int n, m, k, ans=0;
    bool village[11];
    int build[11];
    int cost[11][10005];
    priority_queue<edge> pq;
    iota(p, p+10005, 0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        pq.push({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>build[i];
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }
    while(!pq.empty()){
        edge res = pq.top();
        pq.pop();
        //cout<<res.w<<'\n';
        int u=find(res.u), v=find(res.v);
        if(u==v) continue;
        p[u]=v;
        ans+=res.w;
    }
    cout<<ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    solve();
    return 0;
}
