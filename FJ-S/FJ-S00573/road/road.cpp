#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
int c[15];
int aa[20][N];
int f[N];
struct node {
	int u, v, w;
} a[M << 1];
bool cmp(node x, node y) {
	return x.w < y.w;
}
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
int Union(int x, int y) {
	if (find(x) == find(y)) return 0;// 本身就在同一集合 
	f[find(x)] = find(y);// 不在同一集合 
	return 1;
} 
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
	int tot = m;
	for (int i=1; i<=n; i++) f[i] = i;
	for (int i=1; i<=k; i++) {
		cin >> c[i];
		for (int j=1; j<=n; j++) {
			cin >> aa[i][j];
			a[++tot].u = i;
			a[tot].v = j;
			a[tot].w = aa[i][j] + c[i];
//			cout << aa[i][j] << ' ' << a[tot].w << '\n';
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	int ans = 0;
	for (int i=1; i<=tot; i++) {
		int uu = a[i].u;
		int vv = a[i].v;
		if (Union(uu, vv) == 1) {
			ans += a[i].w;
//			cout << a[i].w << ' '  << uu <<  ' ' << vv << '\n';
		}
	}
	cout << ans + 1 << '\n';
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
