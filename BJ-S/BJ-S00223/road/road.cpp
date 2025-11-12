#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define int long long
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define pre(i,n) for(int i = n;i;--i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define debug cout<<"Help"<<endl
#define swp(x,y) (x ^= y ^= x ^= y)
bool St;
constexpr int N = 1e4 + 5,M = 1e6 + 5,K = 11,inf = 1e17;
int /*head[N],*/fa[N+K],tot,n,m,k,u,v,c,ans;
/*struct edge{
    int v,nxt,c;
}e[(N+K)<<1];
inline void add(int u,int v,int c){
    e[++tot] = {v,head[u],c};
    head[u] = tot;
}*/
struct node{
    int u,v,c;
    inline bool operator < (const node & b) const {
        return c < b.c;
    }
}a[M],b[K*N];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline void init(){
    sort(a + 1,a + m + 1);
    rep(i,m){
        u = a[i].u,v = a[i].v,c = a[i].c;
        if(find(u) ^ find(v)) b[++tot] = a[i],fa[fa[u]] = fa[v],ans += c;
    }
}
bool En;
signed main(){
//    fin("road3.in");
    fin("road.in"),fout("road.out");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    rep(i,n) fa[i] = i;
    rep(i,m) cin>>a[i].u>>a[i].v>>a[i].c;
    init();
    if(!k) return cout<<ans,0;
    // n <= 10^3 && A
    rep(j,k){
        cin>>c;
        rep(i,n) cin>>c,b[++tot] = {j + n,i,c};
    }
    sort(b + 1,b + tot + 1);
    rep(i,n + k) fa[i] = i;
    ans = 0;
    rep(i,tot){
        u = b[i].u,v = b[i].v,c = b[i].c;
        if(find(u) ^ find(v)) fa[fa[u]] = fa[v],ans += c;
    }
    cout<<ans;
    cerr<<'\n'<<clock() * 1.0 / CLOCKS_PER_SEC;
    cerr<<'\n'<<(&En - &St) / 1024.0 / 1024;
    return 0;
}
//Ren5Jie4Di4Ling5%