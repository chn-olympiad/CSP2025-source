#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e4 + 5, M = 1e8 + 5;
int n, m, k, tot, fa[N], zw[N];
int ans;
bool f[N];
struct edge{
	int u, v;
	int w;
	int cz;
}s[M];
bool cmp(edge a, edge b) {
	if (a.w == b.w)
		return a.cz > b.cz;
	return a.w < b.w;
}
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	freopen("road.in", "r" , stdin);
	freopen("road.out", "w" , stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		s[++ tot] = {u, v, w, 0};
	}
	for (int i = 1; i <= k; i ++) {
		int w[N];
		cin >> zw[i];
		for (int j = 1; j <= n; j ++)
			cin >> w[j];
		for (int u = 1; u <= n; u ++)
			for (int v = u + 1; v <= n; v ++) {
				s[++ tot] = {u, v, zw[i] + w[u] + w[v], i};
			}
	}
	f[0] = true;
	sort(s + 1, s + 1 + tot, cmp);
	for (int i = 1; i <= n; i ++)
		fa[i] = i;
	for (int i = 1; i <= tot; i ++) {
		int fu = find(s[i].u), fv = find(s[i].v);
		if (fu != fv) {
			fa[fu] = fv;
			ans += s[i].w;
			n --;
			if (!f[s[i].cz]) {
				for (int k = i + 1; k <= tot; k ++)
					if (s[k].cz == s[i].cz)
						s[k].w -= zw[i];
				sort(s + i + 1, s + 1 + tot, cmp);
			}
		}
		if (n == 1)
			break;
	}
	cout << ans;
	return 0;
}
