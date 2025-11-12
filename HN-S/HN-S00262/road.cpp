#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
struct node {
	int u, v, w;
}e[M + M];
int fa[N], c[N];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool cmp(node a, node b) {
	return a.w < b.w;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	if (k == 0) {
		for (int i = 1; i <= n; ++i) {fa[i] = i;}
		sort(e + 1, e + m + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			int fx = find(e[i].u), fy = find(e[i].v);
			if (fx == fy) continue;
			fa[fy] = fx;
			ans += e[i].w;
		}
		cout << ans << '\n';
		return 0;
	}
	int cnt = m;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		int id = i + n;
		for (int j = 1; j <= n; ++j) {
			int k;
			cin >> k;
			e[++cnt] = {id, j, k + c[i]};
		}
	}
	for (int i = 1; i <= n; ++i) {fa[i] = i;}
	sort(e + 1, e + cnt + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= cnt; ++i) {
		int fx = find(e[i].u), fy = find(e[i].v);
		if (fx == fy) continue;
		fa[fy] = fx;
		ans += e[i].w;
	}
	cout << ans << '\n';
	return 0;
}
