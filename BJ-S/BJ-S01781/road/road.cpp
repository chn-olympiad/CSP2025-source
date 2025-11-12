#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
    int v,w;
};
vector<edge> g[10005];
struct node{
    int cost;
    int dis[10005];
}a[15];
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        ans+=w;
    }
    for(int i=1;i<=k;i++){
        cin>>a[k].cost;
        for(int i=1;i<=n;i++) cin>>a[k].dis[i];
    }
    cout<<ans;
    return 0;
}
