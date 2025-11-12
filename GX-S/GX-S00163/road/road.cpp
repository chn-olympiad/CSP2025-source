#include<bits/stdc++.h>
using namespace std; static int T;
#define reg register
#define _ 100007
#define __ 10000007
#define ___ 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define sz(a) (int)(a.size())
#define pb push_back
#define all(a) a.begin(),a.end()
#define pct __builtin_popcountll
#define ctz __builtin_ctzll
#define endl '\n'
#define debug cerr<<"LINE:     "<<__LINE__<<endl;
#define cln cerr<<"LINE:     "<<__LINE__<<"     "
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define per(i,j,k) for(int i=(j);i>=(k);--i)
#define int unsigned long long
using ll=long long; using ull=unsigned long long; using vt=vector<int>;
using vl=vector<ll>; using pii=pair<int,int>; using pll=pair<ll,ll>; using db=double;
constexpr int M=998244353,M1=1e9+7,M2=1e9+9,N=(1<<21)+7,inf=0x3f3f3f3f;
bool C1;
int n,m,k,fa[_],ans,pt,tot,ptc;
inline int find(int x){ return  x==fa[x]?x:fa[x]=find(fa[x]); }
struct dat{
    int u,v,w;
    inline bool operator<(const dat a)const{ return w<a.w; }
}e[__];
bool C2;
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,l,r,x,y,z;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout)
    cin>>n>>m>>k; pt=m,ptc=n;
    for(i=1;i<=n;++i) fa[i]=i;
    for(i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    stable_sort(e+1,e+pt+1);
    for(i=1;i<=pt;++i){
        int u=find(e[i].u),v=find(e[i].v);
        
        if(u!=v){
            fa[u]=v;
            ans+=e[i].w;
            ++tot;
            if(e[i].u<=n) st.insert(e[i].u);
            if(e[i].v<=n) st.insert(e[i].v);
        }
        if(tot==n-1) break;
    }cout<<ans<<endl;
    return 0;
}