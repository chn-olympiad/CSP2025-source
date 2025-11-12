#include <bits/stdc++.h>
using namespace std;
struct Node {
	int u, v, w;
}e[1000005];
int n, m, k;
bool vis[10005];
bool cmp (Node A, Node B) {
	return A.w < B.w;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1, e + 1 + m, cmp);
	int cnt = 0, ans = 0;
	for (int i = 1; i <= m && cnt != n; i++) {
		bool v1 = vis[e[i].u], v2 = vis[e[i].v];
		if(!v1 || !v2) {
			vis[e[i].u] = 1;
			vis[e[i].v] = 1;
			ans += e[i].w;
		}
	}
	cout << ans;
	return 0;
}
