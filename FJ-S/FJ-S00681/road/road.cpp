#include <bits/stdc++.h>

using namespace std;

int b[10010], n, m, k, o = 1;
vector<pair<int, int>> a[10010];
long long ans;

struct node {
	int i, j, w;
	operator<(const node o) const {
		return w < o.w;
	}
};

bool cmp(node x, node y) {
	return x.w < y.w;
}

priority_queue<node> e;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back({v, w});
	}
	b[1] = 1;
	for (int i = 0; i < a[0].size(); i++) {
		e.push({0, a[0][i].first, a[0][i].second});
	}
	while (o != n && e.empty()) {
		node f = e.top();
		if (!b[f.j]) {
			ans += f.w;
			o += 1;
			b[f.j] = 1;
			for (int i = 0; i < a[f.j].size(); i++) {
				int v = a[f.j][i].first;
				if (!b[v]) {
					e.push({v, a[v][i].first, a[v][i].second});
				}
			}
		}
		e.pop();
	}
	cout << ans;
	
	return 0;
} 
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
