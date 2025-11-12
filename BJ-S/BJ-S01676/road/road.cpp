#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e6+10;
const ll inf=1e18;
ll n,m,res=inf,fa[N],sz[N],tw,cost[15],rd[15][10010];
struct edge{
    ll u,v,w;
}eg[N],neg[N];

ll fnd(ll x){
    return (x==fa[x]?x:fa[x]=fnd(fa[x]));
}

bool mrg(ll u,ll v){
    u=fnd(u),v=fnd(v);
    if(u==v) return false;
    if(sz[u]<sz[v]) swap(u,v);
    sz[u]+=sz[v];
    fa[v]=u;
    return true;
}

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>tw;
    for(ll i=1;i<=m;i++){
        cin>>eg[i].u>>eg[i].v>>eg[i].w;
    }
    for(ll i=1;i<=tw;i++){
        cin>>cost[i];
        for(ll j=1;j<=n;j++){
            cin>>rd[i][j];
        }
    }
    for(ll i=0;i<(1<<tw);i++){
        for(ll j=1;j<=m;j++){
            neg[j]=(edge){eg[j].u,eg[j].v,eg[j].w};
        }
        ll totn=n,totm=m,ans=0;
        for(ll j=1;j<=tw;j++){
            if((i>>(j-1))&1){
                ans+=cost[j];
                totn++;
                for(ll k=1;k<=n;k++){
                    totm++;
                    neg[totm]=(edge){totn,k,rd[j][k]};
                }
            }
        }
        sort(neg+1,neg+totm+1,cmp);
        for(ll j=1;j<=totn;j++){
            fa[j]=j;
        }
        for(ll j=1;j<=totm;j++){
            ll u=neg[j].u,v=neg[j].v,w=neg[j].w;
            if(mrg(u,v)){
                ans+=w;
            }
        }
        res=min(res,ans);
    }
    cout<<res<<"\n";
    return 0;
}
