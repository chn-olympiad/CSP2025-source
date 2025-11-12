#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

#define fi first
#define se second
#define pb push_back

int n,m,k;
struct node {int x,y,w;};
node nd[1000005],op[10005]; int cnt;
bool cmp(const node x,const node y) {return x.w<y.w;}
int val[15][10005]; int c[15];

int fa[10015],sz[10015];
int ff(int x) {return x==fa[x]?x:fa[x]=ff(fa[x]);}
void merge(int x,int y) {x=ff(x);y=ff(y);if(sz[x]>sz[y]) swap(x,y); fa[x]=y;sz[y]=sz[y]+sz[x];}
vector<node> vn;

ll solve(int msk) {
    ll res=0; int p=n-1+__builtin_popcount(msk);
    for(int i=1;i<=k;++i) if((msk>>(i-1))&1) res=res+c[i]; 
    for(int i=1;i<=n+k;++i) fa[i]=i,sz[i]=1;
    int ix=1,iy=0;
    node dd; int e=0;
    for(;ix<=cnt && e<p;) {
        bool tag; 
        if(ix>cnt) tag=false;
        else if(iy==vn.size()) tag=true;
        else tag=(op[ix].w<vn[iy].w); 
        if(tag) dd=op[ix++]; else dd=vn[iy++];
        if(dd.x>n && !((msk>>(dd.x-n-1))&1)) continue;
        if(ff(dd.x)==ff(dd.y)) continue; res=res+dd.w; merge(dd.x,dd.y); ++e; 
    } 
    return res;
} 
 
void wk() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i) scanf("%d%d%d",&nd[i].x,&nd[i].y,&nd[i].w);
    sort(nd+1,nd+m+1,cmp); for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i) {
        if(ff(nd[i].x)==ff(nd[i].y)) continue;
        merge(nd[i].x,nd[i].y); op[++cnt]=nd[i];
    } 
    for(int i=1;i<=k;++i) {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;++j) scanf("%d",&val[i][j]),vn.pb((node){i+n,j,val[i][j]});
    } sort(vn.begin(),vn.end(),cmp);
    ll ans=1ll<<60; //solve(1);
    for(int i=0;i<(1<<k);++i) ans=min(ans,solve(i)); printf("%lld\n",ans);
}

signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    wk();

    return 0;
}

// Make asdfz great again!
/*
password:
Ren5Jie4Di4Ling5%
*/