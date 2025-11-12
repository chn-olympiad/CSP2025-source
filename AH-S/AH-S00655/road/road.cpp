#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
const ll inf=1e16;

int n,m,k,tot;
ll c[15];

struct Edge{
    int u,v;
    ll w;
    bool operator<(Edge g)const{return w<g.w;}
}E[M+N*K],EE[M+N*K];

int fa[N<<1];
int findd(int x){
    if (x==fa[x]) return x;
    return fa[x]=findd(fa[x]);
}

ll calc(int mk){
    ll rt=0;
    up(i,1,k) if (mk>>i-1&1) rt+=c[i];
    up(i,1,n+k) fa[i]=i;
    up(i,1,tot){
        int u=findd(E[i].u),v=findd(E[i].v);
        if (u>n&&((mk>>u-n-1)&1)==0) continue;
        if (v>n&&((mk>>v-n-1)&1)==0) continue;
        ll w=E[i].w;
        if (u==v) continue;
        rt+=w;
        fa[v]=u;
    }
    return rt;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    up(i,1,m) cin>>EE[i].u>>EE[i].v>>EE[i].w;
    sort(EE+1,EE+m+1);
    up(i,1,n) fa[i]=i;
    up(i,1,m){
        int u=findd(EE[i].u),v=findd(EE[i].v);
        if (u==v) continue;
        fa[v]=u;
        E[++tot]=EE[i];
    }
    up(i,1,k){
        cin>>c[i];
        up(j,1,n){
            ll w;cin>>w;
            E[++tot]={j,n+i,w};
        }
    }
    sort(E+1,E+tot+1);
    ll ans=inf;
    up(mk,0,(1<<k)-1) ans=min(ans,calc(mk));
    cout<<ans;
    return 0;
}
