#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node {
	int u, v, w;
}e[N];
int fa[N];

bool cmp(node q, node h) {
	return q.w < h.w;
}

int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= n; ++i) fa[i] = i;
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			e[i].u = u, e[i].v = v, e[i].w = w;
		}
		sort(e + 1, e + 1 + m, cmp);
		long long ans = 0;
		int cnt = 0;
		for (int i = 1; i <= m; ++i) {
			int u = e[i].u, v = e[i].v, w = e[i].w;
			int x = find(u), y = find(v);
			if (cnt == n) break;
			if (x != y) {
				fa[x] = y;
				ans += w;
				cnt++;
			}
		}
		cout << ans;
	}
	return 0;
}
// Ren5Jie4Di4Ling5%
