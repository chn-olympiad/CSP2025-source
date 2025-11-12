#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=1e4+15;
int n,m,k;
vector<pii> g[N];
int c[15],dist[N];
bool vis[N];
int dijk1(int s,int e){
    memset(dist,0x3f,sizeof dist);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(!q.empty()){
        auto tp=q.top();q.pop();
        int x=tp.second,y=tp.first;
        vis[x]=1;
        if(dist[x]<y)continue;
        for(auto &it:g[x]){
            int u=it.second,v=it.first;
            if(dist[u]>dist[x]+v){
                dist[u]=dist[x]+v;
                q.push({dist[u],u});
            }
        }
    }
    return dist[e];
}
int dijk2(int e){
    memset(dist,0x3f,sizeof dist);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for(int i=1;i<=n+k;i++)
        if(vis[i])q.push({0,i});
    while(!q.empty()){
        auto tp=q.top();q.pop();
        int x=tp.second,y=tp.first;
        vis[x]=1;
        if(dist[x]<y)continue;
        for(auto &it:g[x]){
            int u=it.second,v=it.first;
            if(dist[u]>dist[x]+v){
                dist[u]=dist[x]+v;
                q.push({dist[u],u});
            }
        }
    }
    return dist[e];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;cin>>w;
            g[i].push_back({c[i]+w,j+n});
        }
    }
    int min_dist=0x3f;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int next_dist=dijk1(i,j);
            if(min_dist>next_dist){
                min_dist=next_dist;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            min_dist+=dijk2(i);
        }
    }
    cout<<min_dist;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
