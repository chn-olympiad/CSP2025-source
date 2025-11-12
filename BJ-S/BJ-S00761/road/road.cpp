#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e4+100,M=1e6+100;
ll n,m,k,le,f[N],a[15][N],c[15],b[M],lb,sz[N],ans=1e18;
struct Node{ll u,v,w;}e[M],e2[M];
bool cmp(Node x,Node y){
    return x.w<y.w;
}
ll id(ll x){return lower_bound(b+1,b+lb+1,x)-b;}
ll fd(ll x){return (f[x]==x)?x:f[x]=fd(f[x]);}
vector<pair<ll,ll> > E[M];
void rd(ll &x){
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    rd(n);rd(m);rd(k);
    for(ll i=1;i<=m;i++) rd(e[i].u),rd(e[i].v),rd(e[i].w);
    sort(e+1,e+m+1,cmp);
    for(ll i=1;i<=n;i++) f[i]=i;
    for(ll i=1;i<=m;i++){
        ll fx=fd(e[i].u),fy=fd(e[i].v);
        if(fx!=fy){
            f[fx]=fy;
            e2[++le]=e[i];b[++lb]=e[i].w;
        }
    }
    for(ll i=1;i<=k;i++){
        rd(c[i]);
        for(ll j=1;j<=n;j++) rd(a[i][j]),b[++lb]=a[i][j];
    }
    sort(b+1,b+lb+1);lb=unique(b+1,b+lb+1)-b-1;
    for(ll i=1;i<=le;i++) e2[i].w=id(e2[i].w);
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=n;j++) a[i][j]=id(a[i][j]);
    }
    for(ll S=0;S<(1<<k);S++){
        for(ll i=1;i<=lb;i++) E[i].clear();
        for(ll i=1;i<=le;i++) E[e2[i].w].push_back({e2[i].u,e2[i].v});
        for(ll i=1;i<=n+k;i++) f[i]=i,sz[i]=1;
        ll res=0;
        for(ll i=1;i<=k;i++){
            if(S&(1<<(i-1))){
                for(ll j=1;j<=n;j++) E[a[i][j]].push_back({i+n,j});
                res+=c[i];
            }
        }
        for(ll i=1;i<=lb;i++){
            for(pair<ll,ll> p:E[i]){
                ll x=p.first,y=p.second,fx=fd(x),fy=fd(y);
                if(fx==fy) continue;
                if(sz[fx]>sz[fy]) swap(fx,fy);
                f[fx]=fy;sz[fy]+=sz[fx];res+=b[i];
            }
        }
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}
