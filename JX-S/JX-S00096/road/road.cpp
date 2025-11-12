#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5;
constexpr int M = 15;

int n, m, k, u, v, w, c[M];
int arr[M][N], cnt = 0;

struct Edge {
	int u, v, w;
	bool operator<(const Edge& rhs) const {
		return w < rhs.w;
	}
};
vector<Edge> base, Select;

struct DSU {
	int father[N];
	void Init(const int Limit) {
		for (int i = 1; i <= Limit; i++) father[i] = i;
	}
	int Find(const int x) {
		if (father[x] != x) father[x] = Find(father[x]);
		return father[x];
	}
	void Merge(const int x, const int y) {
		int _x = Find(x), _y = Find(y);
		if (_x == _y) return;
		father[_x] = _y;
	}
	bool Same(const int x, const int y) { return Find(x) == Find(y); }
} d;

long long Kruskal(vector<Edge> edges, bool flag = false) {
	sort(edges.begin(), edges.end());
	d.Init(n + k);
	
	long long res = 0;
	// int raise = n, tot = 0;
	
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		if (d.Same(u, v) == false) {
			d.Merge(u, v);
			
			res += w;
			// tot++;
			// raise += (u > n) || (v > n);
			
			// if (tot == raise - 1) break;
			
			if (flag == true) Select.push_back({u, v, w});
		}
	}
	
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int j = 1; j <= m; j++) {
		cin >> u >> v >> w;
		base.push_back({u, v, w});
	}
	
	// bool flag = true;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		// flag = flag && c[i] == 0;
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	
	// if (flag == true) {
		// for (int i = 1; i <= k; i++) {
			// for (int j = 1; j <= n; j++) {
				// base.push_back({n + i, j, arr[i][j]});
			// }
		// }
		
		// cout << Kruskal(base) << "\n";
		// return 0;
	// }
	
	long long answer = Kruskal(base, true);
	
	for (int status = 1; status < (1 << k); status++) {
		base = Select;
		
		long long calc = 0;
		for (int i = 0; i < k; i++) {
			if (status >> i & 1) {
				for (int j = 1; j <= n; j++) {
					base.push_back({i + n + 1, j, arr[i + 1][j]});
				}
				calc += c[i + 1];
			}
		}
		
		if (calc > answer) continue;
		calc += Kruskal(base);
		answer = min(answer, calc);
	}
	
	cout << answer << "\n";
	
	return 0;
}
