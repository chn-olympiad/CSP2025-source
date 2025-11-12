// 最理想应该能骗40 

#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k;
int master[100005];

int init() {
	for (int i = 0; i < 100005; i++) master[i] = i;
}

int find(int x) {
	return x == master[x] ? x : master[x] = find(master[x]);
}

int merge(int l, int r) {
	master[l] = find(r);
}

bool is_merged_union(int l, int r) {
	return find(l) == find(r);
} 

struct Edge {
	int u, v, w;
	friend bool operator<(const Edge& l, const Edge& r) {
		return l.w < r.w;
	}
	friend bool operator>(const Edge& l, const Edge& r) {
		return l.w > r.w;
	}
};

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

void add_edge(int u, int v, int w) {
	pq.push({u, v, w});
}

// 不好好学算法的后果 
int run_kruskal() {
	int merged = 0;
	int result = 0;
	while (!pq.empty() && merged < n - 1) {
		Edge next = pq.top(); pq.pop();
		if (is_merged_union(next.u, next.v)) continue;
		result += next.w;
		merge(next.u, next.v);
		merged++;
	}
	return result;
}

signed main() {
	init();
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
	}
	for (int i = 1; i <= k; i++) {
		int l;
		cin >> l;
		for (int j = 1; j <= n; j++) {
			int u = i, v = j, w;
			cin >> w;
			add_edge(11451 + u, v, w);
		}
	}
	cout << run_kruskal() << endl;
	return 0;
} 
