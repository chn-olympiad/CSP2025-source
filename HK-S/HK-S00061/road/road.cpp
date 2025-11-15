#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e18;
struct edge{
    int u,v,w;
    bool operator<(const edge& edg)const{
        return w<edg.w;
    }
};
struct DSU{
    vector<ll>fa,sz;
    void init(ll n){
        fa.resize(n+5); sz.resize(n+5);
        for(int i=1;i<=n;i++){
            fa[i]=i; sz[i]=1;
        }
    }
    ll rt(ll x){
        if(fa[x]==x)return x;
        return fa[x]=rt(fa[x]);
    }
    void unite(ll u, ll v){
        u=rt(u); v=rt(v);
        if(sz[u]<sz[v])swap(u,v);
        sz[u]+=sz[v]; fa[v]=u;
    }
};
vector<edge>bitmasks[1024];
ll bitmaskans[1024],fixe[1024];
vector<pair<ll,ll> >adj[10005];
ll cost[15]; vector<edge>joining_cost[15];
ll n,m,k;
void resolve(ll ii, ll jj, ll city){
    vector<edge>cur_edges=bitmasks[jj];
    vector<edge>nw=joining_cost[city];
    ll ptr1=0,ptr2=0;
    fixe[ii]=fixe[jj]+cost[city];
    DSU d; d.init(n+k);
    while(ptr1<cur_edges.size()&&ptr2<nw.size()){
        if(cur_edges[ptr1].w<nw[ptr2].w){
            ll u=cur_edges[ptr1].u,v=cur_edges[ptr1].v,w=cur_edges[ptr1].w;
            if(d.rt(u)!=d.rt(v)){
                bitmaskans[ii]+=w; d.unite(u,v); bitmasks[ii].push_back(cur_edges[ptr1]);
            }
            ptr1++;
        }
        else{
            ll u=nw[ptr2].u,v=nw[ptr2].v,w=nw[ptr2].w;
            if(d.rt(u)!=d.rt(v)){
                bitmaskans[ii]+=w; d.unite(u,v); bitmasks[ii].push_back(nw[ptr2]);
            }
            ptr2++;
        }
    }
    if(ptr1<cur_edges.size()){
        for(int i=ptr1;i<cur_edges.size();i++){
            ll u=cur_edges[i].u,v=cur_edges[i].v,w=cur_edges[i].w;
            if(d.rt(u)!=d.rt(v)){
                bitmaskans[ii]+=w; d.unite(u,v); bitmasks[ii].push_back(cur_edges[i]);
            }
        }
    }
    else{
        for(int i=ptr2;i<nw.size();i++){
            ll u=nw[i].u,v=nw[i].v,w=nw[i].w;
            if(d.rt(u)!=d.rt(v)){
                bitmaskans[ii]+=w; d.unite(u,v); bitmasks[ii].push_back(nw[i]);
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    vector<edge>oris;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w}); adj[v].push_back({u,w});
        oris.push_back({u,v,w});
    }
    sort(oris.begin(),oris.end());
    DSU d;
    d.init(n);
    for(int i=0;i<m;i++){
        if(d.rt(oris[i].u)!=d.rt(oris[i].v)){
            bitmaskans[0]+=oris[i].w; d.unite(oris[i].u,oris[i].v);
            bitmasks[0].push_back(oris[i]);
        }
    }
    // cout<<bitmaskans[0]<<" "<<fixe[0]<<'\n';
    fixe[0]=0;
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++){
            int cst; cin>>cst;
            joining_cost[i].push_back({(int)n+i,j,cst});
        }
        sort(joining_cost[i].begin(),joining_cost[i].end());
    }
    for(int i=1;i<(1LL<<k);i++){
        ll bt;
        for(int j=0;j<k;j++){
            if(i&(1LL<<j)){
                bt=j; break;
            }
        }
        resolve(i,(i^(1LL<<bt)),bt+1);
    }
    // for(int i=0;i<(1LL<<k);i++){
    //     cout<<i<<": "<<fixe[i]<<" "<<bitmaskans[i]<<'\n';
    // }
    ll ans=INF;
    for(int i=0;i<(1LL<<k);i++){
        ans=min(ans,fixe[i]+bitmaskans[i]);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--)solve();   
}

/*
    g++ -std=c++2a -O2 road.cpp -o road && ./road
*/