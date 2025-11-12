#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5; // O(m + nk)
const int M = 2e5 + 5;
const int V = 1e4 + 15;

array<int, 3> edge[N];
array<int, 3> G[15][V];
int w[15];

struct dsu {
	int father[V]; int n;
	void init(int x) { n = x; for(int i = 1; i <= n; i++) father[i] = i; }
	int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }
	void bing(int a, int b) { int x = find(a), y = find(b); if(x == y) return; father[y] = x; }
	bool is_root(int x) { return x == find(x); }
	bool same(int a, int b) { return find(a) == find(b); }
} d1;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	d1.init(n);
	for(int i = 1; i <= m; i++) cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
	sort(edge + 1, edge + 1 + m, [&](array<int, 3> p, array<int, 3> q) { return p[2] < q[2]; });
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		if(d1.same(edge[i][0], edge[i][1])) continue;
		G[0][++cnt] = edge[i]; d1.bing(edge[i][0], edge[i][1]);
		if(cnt == n - 1) break; 
	}
	for(int i = 1; i <= k; i++) {
		cin >> w[i];
		for(int j = 1; j <= n; j++)
			cin >> G[i][j][2], G[i][j][0] = i + n, G[i][j][1] = j;
		sort(G[i] + 1, G[i] + 1 + n, [&](array<int, 3> p, array<int, 3> q) { return p[2] < q[2]; });
	}
	//
	int minn = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i < (1 << k); i++) {
		priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
		pq.push({G[0][1][2], {0, 1}});
		int ans = 0; d1.init(n + k);
		for(int j = 1; j <= k; j++) {
			if(i & (1 << j - 1)) {
				pq.push({G[j][1][2], {j, 1}});
				ans += w[j];
			}
		}
		int sum = 0, x = __builtin_popcount(i);
		while(1) {
			auto temp = pq.top(); pq.pop();
			if(!d1.same(G[temp.second.first][temp.second.second][0], G[temp.second.first][temp.second.second][1]))
				sum++, d1.bing(G[temp.second.first][temp.second.second][0], G[temp.second.first][temp.second.second][1]), ans += G[temp.second.first][temp.second.second][2];
			temp.second.second++; temp.first = G[temp.second.first][temp.second.second][2];
			if((temp.first == 0) + temp.second.second <= n) pq.push(temp);
			if(sum == n + x - 1) break;
		}
		minn = min(minn, ans);
	}
	cout << minn << '\n';
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}