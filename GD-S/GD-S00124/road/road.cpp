#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int maxm = 1e6;
constexpr int maxn = 1e4;
int n, m, k;
int fa[maxn + 100];
struct E {
	int u, v;
	LL w;
	bool operator< (const E& oth) const {
		return w < oth.w;
	}
} e[maxm + 10 * maxn + 10];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
LL c[16];
LL a[16][maxn + 10];
void solve() {
	int now = m;
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= n; ++j) {
			++now;
			e[now].u = n + i;
			e[now].v = i;
			e[now].w = 0;
		}
	sort(e + 1, e + 1 + now);
	for (int i = 1; i <= n + k; ++i) fa[i] = i;
	LL ans = 0;
	for (int i = 1; i <= now; ++i) {
		int fu = find(e[i].u);
		int fv = find(e[i].v);
		if (fu != fv) ans += e[i].w, fa[fu] = fv;
	}
	cout << ans << "\n";
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	bool flag = true;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		if (c[i]) flag = false;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	if (flag) {
		solve();
		return 0;
	}
	for (int i = 1; i <= n; ++i) fa[i] = i;
	sort(e + 1, e + 1 + m);
	LL ans = 0;
	for (int i = 1; i <= m; ++i) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) ans += e[i].w, fa[fu] = fv; 
	}
	cout << ans << "\n";
	return 0;
}

