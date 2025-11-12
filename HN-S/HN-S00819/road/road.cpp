#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20;

int n, m, k;
struct Edge {
	int u, v, w;
};
vector<Edge> e;

int f[N];
int c[15];
bool city[15];
vector<int> ct[15];
int ans = 0;

int find_root(int x) {
	if(f[x] == x) {
		return x;
	}
	return f[x] = find_root(f[x]);
}

void merge(int x, int y) {
	int fx = find_root(x), fy = find_root(y);
	if(x != y) {
		f[fx] = fy;
	}
}

bool ck(int u, int v) {
	return find_root(u) != find_root(v);
}

bool cmp(const Edge a, const Edge b) {
	return a.w < b.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++) {
		f[i] = i;
	}
	
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			ct[i].push_back(x);
		}
	}
	
	sort(e.begin(), e.end(), cmp);
	
	for(int i = 0; i < e.size(); i++) {
		Edge ee = e[i];
		if(ck(ee.u, ee.v)) {
			int fu = find_root(ee.u), fv = find_root(ee.v);
			merge(ee.u, ee.v);
			ans += ee.w;
		}
	}
	
	cout << ans << endl;
	return 0;
} 
