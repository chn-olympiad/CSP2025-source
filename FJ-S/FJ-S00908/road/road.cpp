/* CSP 2025 RP++
yuji 64 */
// kuai zuo feng le
#include <bits/stdc++.h>
using namespace std;
int n, k;
struct Edge {
    int u, v, w;
    inline bool operator < (const Edge &o) { return w < o.w; }
} e[(int)2e6], *E;
int dis[(int)1e4 + 50];
vector<pair<int, int> > g[(int)1e4 + 50];
int d[(int)1e4 + 50]; bool vis[(int)1e4 + 50];
vector<int> No;
inline long long prim(void) {
	for (register int i = 1; i <= n + k; ++i) g[i].clear(), d[i] = 0x3f3f3f3f, vis[i] = false;
	for (register int i : No) vis[i] = true;
	d[1] = 0, d[0] = 0x3f3f3f3f;
	for (register Edge *i = e + 1; i <= E; ++i) g[i -> u].emplace_back(i -> v, i -> w), g[i -> v].emplace_back(i -> u, i -> w);
	long long ans = 0;
	for (register int i = n + k - No.size() + 1; --i;) {
		int u = 0;
		for (register int j = 1; j <= n + k; ++j) if (!vis[j] && d[j] < d[u]) u = j;
		ans += d[u], vis[u] = true;
		for (auto &x : g[u]) d[x.first] = min(d[x.first], x.second);
	}
	return ans;
}
long long ans = LLONG_MAX;
int c[12], a[12][(int)1e4 + 50];
void dfs(int x, long long cost) {
	if (x == k + 1) {
		ans = min(ans, prim() + cost);
		return;
	}
	No.emplace_back(n + x);
	dfs(x + 1, cost);
	No.pop_back();
	for (register int i = 1; i <= n; ++i) *++E = (Edge){n + x, i, a[x][i]};
	dfs(x + 1, cost + c[x]), E -= n; 
}
char bf[1 << 25], *ptr = bf;
inline void read(int &x) {
	x = 0; while (!isdigit(*++ptr));
	do x = ((x << 2) + x << 1) + (*ptr ^ 48); while (isdigit(*++ptr));
}
int main() {
	freopen("road.out", "w", stdout);
    fread(bf + 1, (sizeof bf) - 1, 1, fopen("road.in", "r")); 
	int m; read(n), read(m), read(k);
    for (register int i = 1; i <= n + k; ++i) g[i].reserve(n + k);
    E = e + m;
    for (register Edge *i = e + 1; i <= E; ++i) read(i -> u), read(i -> v), read(i -> w);
    bool fg = true;
	for (register int i = 1; i <= k; ++i) {
    	read(c[i]), fg &= c[i] == 0;
    	for (int *j = a[i] + 1, *ed = a[i] + n; j <= ed; ++j) read(*j), fg &= *j == 0;
	}
	if (fg) return cout << 0 << endl, 0;
	dfs(1, 0); cout << ans << endl;
	return 0;
}

