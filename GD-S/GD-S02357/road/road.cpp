#include<bits/stdc++.h>
using namespace std;
struct edge {
	int u, v, w;
} a[2000005];
int c[15];
bool vis[10005];
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, q;
	long long ans = 0;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
	for (int i = 1; i <= q; i++) {
		cin >> c[i + n];
		for (int j = 1; j <= n; j++) {
			int b;
			cin >> b;
			a[++m].u = i + n;
			a[m].v = j;
			a[m].w = b + c[i + n];
		}
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int mar = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == 0) {
				mar = 1;
				break;
			}
		}
		if (!mar) break;
		if (i == 1) {
			if (a[i].u > n && vis[a[i].u]) ans -= c[a[i].u];
			ans += 1ll * a[i].w;
			vis[a[i].u] = 1;
			vis[a[i].v] = 1; 
		} else {
			if (vis[a[i].v] && vis[a[i].u]) continue;
			else {
				if (a[i].u > n && vis[a[i].u]) ans -= c[a[i].u];
				ans += 1ll * a[i].w;
				vis[a[i].u]	= 1;
				vis[a[i].v] = 1;
			}
		}
	}
	cout << ans;
}
