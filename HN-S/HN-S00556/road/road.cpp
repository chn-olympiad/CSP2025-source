#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct ed {
	int u, v, w;
};
vector<ed> edge;
struct dsu {
	vector<int> fa;
	void init(int n) {
		fa.resize(n+1, 0);
		for(int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int find(int n) {
		if(fa[n] != n) return find(fa[n]);
		else return n;
	}
	void un(int a, int b) {
		int Fa = find(a), Fb = find(b);
		if(Fa != Fb) fa[Fa] = Fb;
	}
} d;
void work() {
	int n, m, k;
	cin >> n >> m >> k;
	d.init(n+10);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}
	vector<int> c(n + 5, 0);
	vector<vector<int>> a(k + 5, vector<int>(n + 5, 0));
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		ll cnt = 0, st = 1;
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 0) st = j;
		}
		for(int j = 1; j <= n; j++) {
			if(j == st) continue;
			edge.push_back({st, j, a[i][j]});
		}
	}
	sort(edge.begin(), edge.end(), [](ed a, ed b) -> bool {
		return a.w < b.w;
	});
	ll ans = 0, tmp = 0;
	for(auto now : edge) {
		int nu = now.u, nv = now.v, nw = now.w;
		if(d.find(nu) == d.find(nv)) continue;
		else {
			tmp++;
			d.un(nu, nv);
			ans += nw;
		}
		if(tmp == n - 1) break;
	}
	cout << ans << '\n';
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) {
		work();
	}
	return 0;
}
