#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,r,l) for(int i=(r);i>=(l);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
#define ull unsigned long long
#define it128 __int128
#define vi vector<int>
#define pi pair<int,int>
#define fi first
#define se second
#define vp vector<pi>
#define pl pair<ll,ll>
#define Size(x) ((int)x.size())
const int N=1e4+20,M=1e6+5+10*N;
int n,m,K;
tuple<int,int,int> e[M];
int fa[N],c[15];
int getfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
int r[1<<10][N],tot;
int ee[N*2];
signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>K;
    fo(i,1,n) fa[i]=i;
    fo(i,1,m) {
        int u,v,w; cin>>u>>v>>w;
        e[i]={w,u,v};
    }
    fo(i,1,K) {
        cin>>c[i];
        fo(j,1,n) {
            int w; cin>>w;
            e[m+(i-1)*n+j]={w,i+n,j};
        }
    }
    sort(e+1,e+1+m);
    int tmp=0;
    ll ans=0;
    fo(i,1,m) {
        auto [w,u,v]=e[i];
        u=getfa(u),v=getfa(v);
        if(u!=v) r[0][++tmp]=i,ans+=w,fa[u]=v;
    }
    fu(s,1,1<<K) {
        ll sum=0;
        int popc=0;
        fu(i,0,K) if(s>>i&1) sum+=c[i+1],++popc;
        fo(i,1,n+K) fa[i]=i;
        tot=0;
        fu(i,0,K) if(s>>i&1) {
            int ls=s^(1<<i);
            fo(j,1,n+popc-2) ee[++tot]=r[ls][j];
            fo(j,i*n+m+1,(i+1)*n+m) ee[++tot]=j;
            break;
        }
        sort(ee+1,ee+1+tot,[&](int x,int y) {return get<0>(e[x])<get<0>(e[y]);});
        int tmp=0;
        fo(i,1,tot) {
            auto [w,u,v]=e[ee[i]];
            u=getfa(u),v=getfa(v);
            if(u!=v) r[s][++tmp]=ee[i],sum+=w,fa[u]=v;
        }
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
}