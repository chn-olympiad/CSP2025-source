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
const int MAXN=1e5;
template<typename t1> il bool cmax(t1&x, const t1&y) { return x<y?x=y,1:0; }
template<typename t1> il bool cmin(t1&x, const t1&y) { return y<x?x=y,1:0; }
#define sz(x) ((int)x.size())
int n, p; ai3 a[MAXN+3], tot; bool vis[MAXN+3]; priority_queue<pii> q; ll ans;
int mxid(ai3 x) {return x[0]>=x[1]&&x[0]>=x[2]?0:(x[1]>=x[0]&&x[1]>=x[2]?1:2); }
il void solve() {
    // ll mxm=0;
    cin >> n, tot[0]=tot[1]=tot[2]=0, ans=0; 
    for (int i=1; i<=n; ++i) 
        cin >> a[i][0] >> a[i][1] >> a[i][2],//, mxm+=max(a[i][0], max(a[i][1],a[i][2])),
        tot[mxid(a[i])]++, ans+=a[i][mxid(a[i])], vis[i]=0;
        // max(a[i][0], max(a[i][1],a[i][2]))!=a[i][mxid(a[i])]?cerr << i << endl,1:0;
    // cerr << mxm << endl;
    // cerr << ans << ' ' << mxid(tot) << ' ' << tot[0] << ' ' << tot[1] << ' ' << tot[2] << endl;
    if (tot[p=mxid(tot)]<=(n>>1)) return cout << ans << '\n', void();
    while (!q.empty()) q.pop();
    for (int i=1; i<=n; ++i) if (mxid(a[i])==p)
        for (int o=0; o<=2; ++o) if (o!=p) q.push({a[i][o]-a[i][p], i});
    for (int u, v, c=tot[p]; c>(n>>1); ) {
        u=q.top().se, v=q.top().fi, q.pop();
        if (!vis[u]) vis[u]=1, c--, ans+=v;
        // cerr << u << ' ' << v << endl; 
    }
    cout << ans << '\n';
}
db Tbe; bool Men;
int main() {
#ifdef MYFRE
    Tbe=clock();
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
    // solve();
    int t; cin >> t; while (t--) solve();
#ifdef MYFRE
    cerr << "M: " << (&Mbe-&Men)/1024.0/1024 << " T: " <<  (clock()-Tbe)/1e6 << endl;
#endif
}
