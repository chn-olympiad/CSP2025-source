#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 1e4 + 10, M = 1e6 + 10;
struct Edge {
	int x, y, z;
}e[M * 2];
int fa[N], lin[N];
int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}
void merge(int x, int y) {
	int fx = get(x), fy = get(y);
	fa[fx] = fy;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) cin >> e[i].x >> e[i].y >> e[i].z;
	for (int i = 1; i <= k; i++) {
		int x; cin >> x;
		for (int j = 1; j <= n; j++) {
			cin >> lin[j];
			if (lin[j] == 0) x = j;
		}
		for (int j = 1; j <= n; j++)
			if (j != x) e[++m] = Edge{x, j, lin[j]};
	}
	sort(e + 1, e + m + 1, [&](Edge x, Edge y) {return x.z < y.z;});
	int ans = 0;
	for (int i = 1; i <= m; i++) {
//		cout << e[i].x << " " << e[i].y << "\n";
		if (get(e[i].x) == get(e[i].y)) continue;
		ans += e[i].z;
		merge(e[i].x, e[i].y);
	}
	cout << ans << "\n"; 
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 100 4 100
0 100 0 100 100
*/
