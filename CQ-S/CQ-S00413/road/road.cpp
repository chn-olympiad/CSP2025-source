#include<bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = (x); i <= (y); ++i)
#define drep(i, x, y) for(int i = (x); i >= (y); --i)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
inline void Fin(string s) { freopen((s + ".in").c_str(), "r", stdin); }
inline void Fout(string s) { freopen((s + ".out").c_str(), "w", stdout); }
const int N = 10030, M = 1e6 + 5;
struct edge { int u, v, w; } G[1 << 10][N], E[M];
int fa[N], n, m, c[20], k, sz[1 << 10];
ll ans[1 << 10];
edge a[12][N];
#define gc getchar
inline void rd(int &x) {
	x = 0; static char c = gc();
	while(c < '0' || c > '9') c = gc();
	while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
	return;
}
inline bool cmp(const edge &x, const edge &y) { return x.w < y.w; }
inline int fd(int x) {
	if(fa[x] == x) return x;
	return fa[x] = fd(fa[x]);
}
inline bool mrg(int x, int y) {
	x = fd(x), y = fd(y);
	if(x == y) return 0;
	return fa[x] = y, 1;
}
inline void clear() { rep(i, 1, n + k) fa[i] = i; }
ll sum = 0; int now = 0; 
inline void lnk(const edge &e) { if(mrg(e.u, e.v)) sum += e.w, G[now][++sz[now]] = e; }
inline void sol(int x, int u, int i) {
	int p = 1, q = 1; clear();
//	cout << "sl : " << x << ' ' << u << ' ' << i << '\n';
	now = i, sum = 0;
	while(p <= sz[x] || q <= n) {
		if(p > sz[x] || (q <= n && a[u][q].w <= G[x][p].w)) lnk(a[u][q++]);
		else lnk(G[x][p++]);
	}
	ans[i] = sum;
}
int main() {
	Fin("road"), Fout("road");
	fastio;
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> E[i].u >> E[i].v >> E[i].w;
	sort(E + 1, E + 1 + m, cmp);
	rep(i, 1, k) {
		cin >> c[i];
		rep(j, 1, n) cin >> a[i][j].w, a[i][j].u = i + n, a[i][j].v = j;
		sort(a[i] + 1, a[i] + 1 + n, cmp);
	}
	clear();
	rep(i, 1, m) if(mrg(E[i].u, E[i].v)) G[0][++sz[0]] = E[i], ans[0] += E[i].w;
	rep(i, 1, (1 << k) - 1) sol(i ^ (i & -i), __lg(i & -i) + 1, i);
	ll res = 1e18;
	rep(i, 0, (1 << k) - 1) rep(j, 0, k - 1) if((i >> j) & 1) ans[i] += c[j + 1];
	rep(i, 0, (1 << k) - 1) res = min(res, ans[i]);//, cout << "AS : " << i << " = " << ans[i] << '\n';
	cout << res << '\n';
	return 0;
}

