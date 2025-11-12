#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int maxn = 1e5 + 10;

int n, m, k;
struct node {
	int u, v, w;
	bool operator < (const node &o) const {return w < o.w;}
}e[maxn];
int tot, ans;
int f[maxn];

int find(int x) {return (x == f[x] ? x : f[x] = find(f[x]));}

void kruskal() {
	sort(e + 1, e + m + 1);
	for (int i = 1, u, v, w; i <= m; ++i) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		u = find(u), v = find(v);
		if (u != v) {
			f[u] = v;
			ans += w;
			if (++tot == n - 1) break;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) 
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1, w; j <= n; ++j)
			cin >> w, e[++m] = {j, 0, w};
	}
	for (int i = 0; i <= n; ++i) f[i] = i;
	kruskal();
	cout << ans << '\n';
	return 0;
}
