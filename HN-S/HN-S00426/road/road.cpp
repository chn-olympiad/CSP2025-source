#include<bits/stdc++.h>
using namespace std;
struct node {
	int u, v, w;
};
int n, m, k, cnt, c[20];
node q[1000010];
int fa[10010];
bool flag = true;
bool cmp(node a, node b) {
	return a.w < b.w;
}
int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
void kruskal() {
	int s = 0, ans = 0;
//	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) {
		int u = q[i].u, v = q[i].v, w = q[i].w;
		if (find(u) != find(v)) {
//			cout << q[i].u << ' ' << q[i].v << ' ' << q[i].w << ' ';
			fa[find(u)] = find(v);
			s++;
			ans += w;
//			cout << ans << endl;
		}
		if (s == n - 1) {
			cout << ans << endl;
			return;
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cnt++;
		cin >> q[cnt].u >> q[cnt].v >> q[cnt].w;
	}
//	for (int i = 1; i <= k; i++) {
//		cin >> c[i];
//		if (c[i]) flag = false;
//		for (int j = 1; j <= n; j++) {
//			cin >> q[++cnt].w;
//			q[cnt].u = n + i, q[cnt].v = j;
//		}
//	}
//	if (k == 0) {
	sort(q + 1, q + cnt + 1, cmp);
	kruskal();
//	}
	return 0;
}
