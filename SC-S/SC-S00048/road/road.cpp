#include <bits/stdc++.h>

using namespace std; 

struct Edge {
	int u, v; 
	long long w;
	bool operator < (const Edge& Rt) const {
		return w > Rt.w;
	}
};

int n, m, k; 
long long sum, minx; 
priority_queue<Edge> T;
int U[10015]; 
long long C[10], A[10][100005];

void Merge (int u, int v) {
	U[u] = v;
}

int Find (int x) {
	if (U[x] == x) return x;
	else return U[x] = Find(U[x]);
}

void Solve () {
	while (T.size()) {
		int tu = T.top().u;
		int tv = T.top().v;
		long long tw = T.top().w; 
		
		T.pop();
		
		if (Find(tu) == Find(tv)) continue; 
		Merge(Find(tu), Find(tv));
		sum += tw;
	}
	
	minx = min(minx, sum);
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 

	priority_queue<Edge> P;

	int u, v; 
	long long w;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		P.push({u, v, w});
	}
	
	for (int i = 0; i < k; i++) {
		cin >> C[i];
		for (int j = 1; j <= n; j++) 
			cin >> A[i][j];
	}
	
	minx = 2e18;
	
	for (int tt = 0; tt < (1 << k); tt++) {
		sum = 0;
		T = P;
		for (int i = 1; i <= n + k + 1; i++) 
			U[i] = i;
		for (int i = 0; i < k; i++) {
			if ((tt >> i) & 1) {
				sum += C[i];
				for (int j = 1; j <= n; j++) {
					T.push({n + 1 + i, j, A[i][j]});
				}
			}
		}
		Solve();
	}
	
	cout << minx;
	
	return 0;
}