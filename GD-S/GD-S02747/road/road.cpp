#include <bits/stdc++.h>
using namespace std;

struct Node {
	int x, y, z;
} edge[2000005];
int f[10005];
int find(int x) {
	if(x == f[x]) return x;
	else return f[x] = find(f[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0, cnt = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		cin >> edge[i].x >> edge[i].y >> edge[i].z;
	}
	vector<vector<int>> a(k + 1, vector<int> (n + 1));
	vector<int> c(k + 1);
	for(int i = 1; i <= k; ++i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			edge[++m].x = i, edge[m].y = j, edge[m].z = a[i][j];
		}
	}
	sort(edge + 1, edge + m + 1, [&] (const Node& x, const Node& y) {
		return x.z < y.z;	
	});
//	for(int i = 1; i <= m; ++i) {
//		cout << edge[i].x << ' ' << edge[i].y << ' ' << edge[i].z << '\n';
//	}
	for(int i = 0; i <= n; ++i) f[i] = i;
	for(int i = 1; i <= m; ++i) {
		int fx = find(edge[i].x);
		int fy = find(edge[i].y);
//		cout << fx << ' ' << fy << '\n';
		if(fx == fy) continue;
		f[fx] = fy;
		ans += edge[i].z;
		cnt++;
		if(cnt == n - 1) break;
	}
	if(cnt == n - 1) cout << ans << '\n';
//	cout << 1 << '\n';
	return 0;
}
