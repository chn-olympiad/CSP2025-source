#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edg{
    ll u,v,w;
    edg(const ll &A=0,const ll &B=0,const ll &C=0):u(A),v(B),w(C){}
    inline bool operator<(const edg &a) const{
        return w<a.w;
    }
};
ll n,m,k;
ll par[10005],c[10][10005];
edg e[2000005];
inline void init(){
    for(ll i=1;i<=n;i++) par[i]=i;
    return;
}
inline ll sfind(const ll &x){return par[x]==x?x:par[x]=sfind(par[x]);}
inline bool inset(const ll &x,const ll &y){return sfind(x)==sfind(y);}
inline void smerge(ll x,ll y){
    if(inset(x,y)) return;
    x=sfind(x),y=sfind(y);
    par[y]=x;
    return;
}
inline ll kruskal(){
    ll res=0;
    sort(e+1,e+1+m);
    init();
    for(ll i=1;i<=m;i++){
        if(inset(e[i].u,e[i].v)) continue;
        smerge(e[i].u,e[i].v);
        res+=e[i].w;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(ll i=0;i<k;i++) for(ll j=0;j<=n;j++) cin>>c[i][j];
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            e[++m]=edg(i,j,1e18);
            for(ll l=0;l<k;l++) e[m].w=min(c[l][i]+c[l][j],e[m].w);
        }
    }
    cout<<kruskal();
    return 0;
}
