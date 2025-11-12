#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 20015, M = 1000005, mod = 998244353;
struct node {
	int u, v, w;
} b[M], a[10][N], e[1 << 10][N];
inline bool cmp(node &x, node &y) {
	return x.w < y.w;
}
int n, up, f[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
inline bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v)
		return 0;
	f[u] = v;
	return 1;
}
inline ll work(int cc, int m, node *a, node *b) {
	for (int i = 1; i <= up; i++)
		f[i] = i;
	int k = 0;
	ll res = 0;
	for (int i = 1; i <= m; i++) {
		if (merge(a[i].u, a[i].v)) {
			b[++k] = a[i];
			res += a[i].w;
		}
		if (k == cc)
			break;
	}
	return res;
}
int c[10], sz[1 << 10];
ll sum[1 << 10];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int m, k;
	cin >> n >> m >> k;
	up = n + k;
	for (int i = 1; i <= m; i++)
		cin >> b[i].u >> b[i].v >> b[i].w;
	sort(b + 1, b + m + 1, cmp);
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j].w;
			a[i][j].u = n + i + 1, a[i][j].v = j;
		}
		sort(a[i] + 1, a[i] + n + 1, cmp);
	}
	ll res = work((sz[0] = n - 1), m, b, e[0]);
	for (int i = 1; i < (1 << k); i++) {
		int to = i & (i - 1), x = __builtin_ctz(i);
		merge(e[to] + 1, e[to] + sz[to] + 1, a[x] + 1, a[x] + n + 1, b + 1, cmp);
		int cur = sz[to] + n;
		res = min(res, (sum[i] = sum[to] + c[x]) + work((sz[i] = sz[to] + 1), cur, b, e[i]));
	}
	cout << res << '\n';
	return 0;
}
