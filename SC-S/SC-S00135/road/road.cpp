#include<bits/stdc++.h>
using namespace std;
#define nmax 10007
#define int long long
int n, m, k;
struct node {
	int v, w;
};

vector<node> mp[nmax];
int c[nmax];
int a[20][nmax];

struct edge {
	int u, v, w;
	bool operator <(const edge& o) {
		return w < o.w;
	}
};

vector<edge> edges;

int fa[nmax];
int getfa(int x) {
	if (fa[x] == x) {
		return x;
	}

	fa[x] = getfa(fa[x]);
	return fa[x];
}

int klsker(int tot) {
	for (int i = 1; i <= tot + 1; i++) {
		fa[i] = i;
	}

	int res = 0;
	sort(edges.begin(), edges.end());
	int cnt = 0;

	for (int i = 0; cnt != tot - 1; i++) {
		int u = edges[i].u;
		int v = edges[i].v;

		if (getfa(u) == getfa(v)) {
			continue;
		}

		res += edges[i].w;
		cnt++;
		fa[getfa(u)] = getfa(v);
	}

	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;

	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		mp[u].push_back({v, w});
		mp[v].push_back({u, w});
		edges.push_back({u, v, w});
		edges.push_back({v, u, w});
	}

	for (int j = 0; j < k; j++) {
		cin >> c[j];

		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
	}

	int ans = INT_MAX;

	for (int i = 0; i <= (1 << k) - 1; i++) { // i[x]:第x号乡村是否建立
		int res = 0, tot = n;

		for (int j = 0; j < 12; j++) {
			if ((i >> j) & 1) { // J[j]号村成立
				res += c[j]; // 建村费用
				tot++;

				for (int i = 1; i <= n; i++) {
					edges.push_back({n + j + 1, i, a[j][i]});
					edges.push_back({i, n + j + 1, a[j][i]});
				}
			}
		}

		ans = min(ans, klsker(tot) + res);

		while ((int)edges.size() != m * 2) {
			edges.pop_back();
		}
	}

	cout << ans;

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