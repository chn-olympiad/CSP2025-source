#include <bits/stdc++.h>
#define N 20005
#define K 15
#define M 1000005
#define ll long long
using namespace std;
ll n, m, k, a[K][N], fa[N + K], ans = 1e18, res, ecnt, cnt, f[N];
struct edge {
	ll u, v, w;
	friend bool operator < (edge a, edge b) {
		return a.w < b.w;
	}
} e[M + N * K], g[N];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
ll solve(int m, int cnt, int flag) {
	sort(e + 1, e + 1 + m);
	ll ret = 0;
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 1; i <= m && cnt; i++) {
		ll u = e[i].u, v = e[i].v, w = e[i].w;
		u = find(u), v = find(v);
		if (u != v) {
			fa[u] = v;
			if (ret + res >= ans) return 1e18;
			if (flag) g[++ecnt] = {u, v, w};
			ret += w;
			cnt--;
			if (!cnt) break;
		}
	}
	return ret;
}
int main() {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++) cin >> a[i][j];
	
	f[0] = ans = solve(m, n - 1, 1);
	
	for (int i = (1 << k) - 1; i >= 1; i--) {
		res = 0, ecnt = 0, cnt = n - 1;
		for (int j = 1; j < n; j++) e[++ecnt] = g[j];
		for (int j = 1; j <= k; j++)
			if (i & (1 << j - 1)) {
				res += a[j][0];
				if (res >= ans) break;
				
				cnt++;
				for (int l = 1; l <= n; l++)
					e[++ecnt] = {n + j, l, a[j][l]};
				
			} else if (f[i | (1 << j - 1)] - a[j][0] >= ans) {
				res = 1e18;
				break;
			}
		if (res >= ans) continue;
		ll x = solve(ecnt, cnt, 0);
		f[i] = x + res;
		ans = min(ans, res + x);
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
