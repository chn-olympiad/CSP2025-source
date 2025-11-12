#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+1e3,M=2e6+10,K=11;
ll n,m,k,c[N],f[N],sz[N],lx,ans,lq;
pair<ll,ll> ln[M];
vector<pair<ll,ll> > g[N];
pair<ll,ll> q[M];
inline ll find(ll x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
inline void merge(ll u,ll v){
    u=find(u);
    v=find(v);
    if(sz[u]>sz[v]){
        f[v]=u;
        sz[u]+=sz[v];
    }else{
        f[u]=v;
        sz[v]+=sz[u];
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        ln[++lx]={u,v};
        q[lq++]={-w,lx};
    }
    for(ll i=1;i<=k;i++){
        cin>>c[i];
        for(ll j=1;j<=n;j++){
            ll w;
            cin>>w;
            g[n+i].push_back({j,w});
            g[j].push_back({n+i,w});
            ln[++lx]={n+i,j};
            q[lq++]={-w,lx};
        }
    }
    for(ll i=1;i<=lx;i++){
        f[i]=i;
        sz[i]=1;
    }
    sort(q,q+lq);
    int top=lq;
    while(top>=0){
        pair<ll,ll> temp=q[top--];
        ll d=temp.first;
        ll u=ln[temp.second].first;
        ll v=ln[temp.second].second;
        if(find(u)!=find(v)){
            ans-=d;
            merge(u,v);
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 6 4
0 4 7 0 6

*/