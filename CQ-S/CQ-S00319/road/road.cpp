#include<bits/stdc++.h> 
bool Mbe;
using namespace std;
#define il inline
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define fi first
#define se second 
typedef array<int,3> ai3;
const int MAXN=1e4+10, MAXK=10;
template<typename t1> il bool cmax(t1&x, const t1&y) { return x<y?x=y,1:0; }
template<typename t1> il bool cmin(t1&x, const t1&y) { return y<x?x=y,1:0; }
#define sz(x) ((int)x.size())
int n, m, k, a[MAXN+3][MAXN+3]; ll ans, oth;
struct Edge {int u,v,w; } E0[MAXN+3]; 
il bool operator<(Edge c, Edge d) {return c.w<d.w; }
namespace dsu {
    int f[MAXN+3]; int find(int u) {return f[u]^u?f[u]=find(f[u]):u; }
    il void init(int n) {for (int i=1; i<=n; ++i) f[i]=i; }
} using namespace dsu;
namespace kru {
    const int MAXM=1e6;
    Edge E[MAXM+3];
    il void work(bool ty, ll re=0) {
        sort(E+1, E+1+m), dsu::init(n+k);
        for (int ei=1, c=0; ei<=m; ++ei) if (find(E[ei].u)!=find(E[ei].v)) {
            f[find(E[ei].v)]=find(E[ei].u), re+=E[ei].w;
            if (ty) E0[++c]=E[ei];
        }
        if (ty) ans=re; else cmin(ans, re+oth);
    }
}
il void solve() {
    cin >> n >> m >> k;
    for (int ei=1,u,v,w; ei<=m; ++ei) cin >> u >> v >> w, kru::E[ei]={u,v,w}; 
    kru::work(1); 
    for (int i=0; i<k; ++i) 
        for (int j=0; j<=n; ++j) cin >> a[i][j];
    for (int s=0; s<(1<<k); ++s) {
        m=n-1; for (int ei=1; ei<n; ++ei) kru::E[ei]=E0[ei];
        oth=0; for (int j=0; j<k; ++j) if (s>>j&1) {
            oth+=a[j][0];
            for (int i=1; i<=n; ++i) kru::E[++m]={i,n+j+1,a[j][i]}; 
        }
        kru::work(0);
    }
    cout << ans;
}
db Tbe; bool Men;
int main() {
#ifdef MYFRE
    Tbe=clock();
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
    solve();
    // int t; cin >> t; while (t--) solve();
#ifdef MYFRE
    cerr << "M: " << (&Mbe-&Men)/1024.0/1024 << " T: " <<  (clock()-Tbe)/1e6 << endl;
#endif
}