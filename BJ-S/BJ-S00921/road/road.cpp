#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
#define ll long long

const ll N=1e4+10;
struct edge{
    ll v,w;
};
vector<edge> g[N];
struct node{
    ll v,w;
    friend bool operator<(node a,node b){
        return a.w>b.w;
    }
};
ll n,m,k,vis[N],dis[N],c[N][N];

void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    priority_queue<node> q;
    q.push({1,0});
    
    while(!q.empty()){
        ll u=q.top().v;
        q.pop();

        if(vis[u]==1) continue;
        vis[u]=1;

        for(auto t:g[u]){
            ll v=t.v,w=t.w;
            if(dis[v]>dis[u]+w){
                // cout<<u<<"->"<<v<<' '<<w<<' '<<dis[v]<<"->"<<dis[u]+w<<endl;
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({w,u});
    }
    bool flag=true;
    for(ll i=1;i<=k;i++){
        cin>>c[i][0];
        for(ll j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]!=0) flag=false;
        }
    }

    if(!flag){
        dijkstra();
        // for(ll i=1;i<=n;i++) cout<<dis[i]<<' ';
        // cout<<endl;
        cout<<dis[n]<<endl;
    }else cout<<0<<endl;
    return 0;
}