#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=10005;
#define int long long
constexpr int INF=0x3f3f3f3f3f3f3f3fLL;
#define pir pair<int,int>
int n,m,k,ans;
vector<pir> e[MAXN];
int dis[MAXN],mdis[MAXN];
bitset<MAXN> vis;
int lin[MAXN];
struct edge{
    int fa,first,second;
    edge(){}
    edge(int first,int second,int fa):
        first(first),second(second),fa(fa)
    {}
    bool operator< (const edge &rhs) const {
        return second>rhs.second;
    }
};
priority_queue<edge> q;
void prim(){
    for(int i=1;i<=n;++i)
        dis[i]=INF;
    dis[1]=0;
    q.push(edge(1,0,0));
    while(!q.empty()){
        int u=q.top().first;
        int fa=q.top().fa;
        int w=q.top().second;
        q.pop();
        if(vis[u])
            continue;
        ans+=w;
        vis[u]=1;
        mdis[u]=max(mdis[fa],w);
        for(auto i:e[u])
            if(dis[i.first]>i.second){
                dis[i.first]=i.second;
                // mdis[i.first]=max(mdis[i.first].i.second);
                q.push(edge(i.first,i.second,u));
            }
    }
    return;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].emplace_back(make_pair(v,w));
        e[v].emplace_back(make_pair(u,w));
    }
    // for(int i=1;i<=n;++i){
    //     int c;
    //     cin>>c;
    //     for(int i=1;i<=n;++i){
    //         cin>>lin[i];
    //         lin[i]+=c;
    //     }
    // }
    prim();
    // if(k==0){
        cout<<ans;
        return 0;
    // }

    // }
    return 0;
}
