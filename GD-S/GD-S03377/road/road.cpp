#include <bits/stdc++.h>

using namespace std;

struct V {
	int from, to, w;
};

int n, m, k, num_edge, f[10007], ans;
vector<V> edge;

int find (int x) {
	return (f[x] == x) ? x : f[x] = find(f[x]);
}

bool cmp (V x, V y) {
	return x.w < y.w;
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge.push_back({x, y, z});
//		edge.push_back({y, x, z});
	}
	sort(edge.begin(), edge.end(), cmp);
//	for (int i = 0; i < m * 2; i++) {
//		cout << edge[i].from << " " << edge[i].to << " " << edge[i].w << "\n";
//	}
	int cnt = 1;
	for (int i = 0; i < m; i++) {
		int x = find(edge[i].from);
		int y = find(edge[i].to);
		if (x == y) continue;
		ans += edge[i].w;
		f[x] = y;
//		f[y] = x;
		cnt += 1;
//		if (cnt >= n + 1) break;
//		cout << cnt << "\n";
	}
	cout << ans;
	return 0; 
}
