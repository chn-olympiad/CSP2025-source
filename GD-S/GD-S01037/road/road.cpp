#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define INF 1e18
#define endl '\n'

using namespace std;

const int N = 1e4 + 20, M = 1e6 + 5;

int fa[N];
int n, m, k;
int c[12], le[12][N];
bool fl[N];

struct Node {
	int u, v, w;
	bool operator<(const Node &other) const {
		return w < other.w;
	}
} a[M + N * 10];

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	int ecnt = m;
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			cin >> le[i][j];
			a[ ++ ecnt] = {i + n, j, le[i][j]};
		}
	}
	sort(a + 1, a + ecnt + 1);
//	for (int i = 1; i <= ecnt; i ++) {
//		cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w << endl;
//	}
	ll ans = INF;
	for (int i = 0; i < (1 << k); i ++) {
		for (int j = 1; j <= n + k; j ++) fa[j] = j;
		ll res = 0; int ncnt = n;
		for (int j = 1; j <= k; j ++) {
			fl[j] = 0;
			if (i & (1 << (j - 1))) fl[j] = 1, ncnt ++, res += c[j];
		}
		int tot = 0;
		for (int j = 1; tot < ncnt - 1; j ++) {
			int u = a[j].u, v = a[j].v, w = a[j].w;
			if ((u > n && !fl[u - n]) || find(u) == find(v)) continue;
			fa[find(v)] = find(u);
			tot ++; res += w;
		}
		ans = min(ans, res);
//		cerr << i << endl;
	}
	cout << ans;
	return 0;
}
