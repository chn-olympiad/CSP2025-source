#include <bits/stdc++.h>
#define rept(i,a,b) for(int i(a);i<=(b);++i)
#define rep(i,a,b) for(int i(a);i<(b);++i)
#define pert(i,a,b) for(int i(a);i>=(b);--i)
#define per(i,a,b) for(int i(a);i>(b);--i)
#define lowbit(x) ((x)&-(x))
#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
#define eb emplace_back
#define pb push_back
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin))==buf?EOF:*p1++)
#define pii pair<int,int>
#define umap unordered_map
#define uset unordered_set
#define mmap multimap
#define mset multiset
#define ll long long
#define db double
#define ldb long double
#define pct __builtin_popcount
#define pctll __builtin_popcountll
using namespace std;
const int N=1e4+20,K=20;
char buf[1<<20],*p1,*p2;
inline int rd(){
    int x;char c;
    while((c=gc)<'0'||c>'9');
    for(x=c^48;(c=gc)>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^48));
    return x;
}
struct Edge{
    int u,v,w;
    Edge()=default;
    Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    inline bool operator<(const Edge &rhs) const {
        return w<rhs.w;
    }
};
vector<Edge> e,f,g[K],h;
int n,m,k,tot,tgt;
ll ans,cur;
int fa[N],c[K];
void init(int lim){
    rept(i,1,lim) fa[i]=i;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=rd(),m=rd(),k=rd();
    rept(i,1,m){
        int u=rd(),v=rd(),w=rd();
        e.eb(u,v,w);
    }
    rept(i,1,k){
        c[i]=rd();
        rept(j,1,n){
            int w=rd();
            g[i].eb(i+n,j,w);
        }
    }
    sort(e.begin(),e.end());
    init(n);
    tot=0;
    rep(i,0,e.size()){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int x=find(u),y=find(v);
        if(x^y){
            fa[x]=y;
            ans+=w;
            f.eb(e[i]);
            ++tot;
            if(tot==n-1) break;
        }
    }
    rep(msk,1,1<<k){
        cur=0;
        tgt=n+pct(msk);
        h=f;
        rept(i,1,k){
            if(msk>>(i-1)&1){
                cur+=c[i];
                rep(j,0,g[i].size()) h.eb(g[i][j]);
            }
        }
        sort(h.begin(),h.end());
        init(n+k);
        tot=0;
        rep(i,0,h.size()){
            int u=h[i].u,v=h[i].v,w=h[i].w;
            int x=find(u),y=find(v);
            if(x^y){
                fa[x]=y;
                cur+=w;
                ++tot;
                if(tot==tgt-1) break;
            }
        }
        ans=min(ans,cur);
    }
    printf("%lld\n",ans);
    return 0;
}

