#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
const int M = 2e6 + 10;
const int K = 20;
const int INF = 1e9;
struct Edge {
	int u, v, w;
} g[M], f[M];
int n, m, k, cnt, s[K], c[K], a[K][N], fth[N];
long long ans;

bool cmp(const Edge &x, const Edge &y) {
	return x.w < y.w;
}

int findset(int u) {
	if (fth[u] == u)
		return u;
	fth[u] = findset(fth[u]);
	return fth[u];
}

long long solve(int len) {
	for (int i = 1; i <= n; i++)
		fth[i] = i;
	for (int i = 1; i <= m; i++)
		g[i] = f[i];
	int l = m;
	for (int i = 1; i <= n; i++) {
		for (int p = i + 1; p <= n; p++) {
			int val = INF;
			for (int j = 1; j <= len; j++)
				val = min(val, a[s[j]][i] + a[s[j]][p]);
			g[++l].u = i;
			g[l].v = p;
			g[l].w = val;
		}
	}
	sort(g + 1, g + l + 1, cmp);
	long long res = 0;
	for (int i = 1; i <= l; i++) {
		int u = g[i].u, v = g[i].v, w = g[i].w;
		int fu = findset(u), fv = findset(v);
		if (fu != fv) {
			fth[fu] = fv;
			res += w;
			if (res >= ans)
				return res;
		}
 	}
 	return res;
}

void dfs(int x, int y, long long w) {
	if (w >= ans)
		return;
	if (x > k) {
		ans = min(ans, w + solve(y));
		return;
	} 
	dfs(x + 1, y, w);
	s[y + 1] = x;
	dfs(x + 1, y + 1, w + c[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) 
		cin >> f[i].u >> f[i].v >> f[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	ans = 1e18;
	dfs(1, 0, 0);
	cout << ans << "\n";
	return 0;
}
