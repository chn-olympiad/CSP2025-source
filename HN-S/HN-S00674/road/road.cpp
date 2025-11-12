#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10, M =  2e6 + 10;
ll  n, m, k, d[20][N], fa[N], cnt, ans, vis[20], s[N];
vector<int> G;
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
struct edge {
	ll u, v, w;
	bool operator < (edge other) const {
	    return w < other.w;
	}
}e[M];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + 1 + m); 
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		fa[fu] = fv;
		ans += w;
		cnt++;
		G.push_back(i);
		if (cnt == n - 1) break;
	}
	cout << ans << '\n';
	return 0;
}
