#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
struct node{
	int u, v, w, town;
};
vector <node> e;
int c[N];
int fa[N];
void pre() {
	for(int i = 0; i <= n; i++) fa[i] = i;
}
int find(int x) {
	return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}
bool vis[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		int a;
		for(int j = 1; j <= n; j++) {
			cin >> a;
			e.push_back({n + i, j, a + c[i], i});
		}
	}
	sort(e.begin(), e.end(), [&] (const node in1, const node in2) {
		return in1.w < in2.w;
	});
	
	pre();
	int ans = 0;
	for(int i = 0; i < e.size(); i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w, town = e[i].town;
//		cout << u << " " << v << " " << w << " " << town << "\n";
		if(town == -1) {
			int fu = find(u), fv = find(v);
			if(fu != fv) {
				ans += w;
				fa[fu] = fv;
			}
		} else {
			if(vis[town]) {
				int fu = find(u), fv = find(v);
				if(fu != fv) {
					ans += w - c[town];
					fa[fu] = fv;
				}
			} else {
				int fu = find(u), fv = find(v);
				if(fu != fv) {
					ans += w;
					vis[town] = 1;
					fa[fu] = fv;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
