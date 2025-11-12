#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, k, ans;
int a[10005][10005];
struct edge {
	int u, v, w;
};
vector<edge> E;

int fa[10005];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y) { fa[find(y)] = find(x); }

int kruskal() {
	sort(E.begin(), E.end(), [](edge x, edge y) { return x.w < y.w; });
	int cnt = 0, ans = 0;
  for (int i = 1; i <= n; i++)
  	fa[i] = i;
	for (auto i : E) {
		int u = find(i.u);
		int v = find(i.v);
		if (u == v)
			continue;
		unite(u, v);
		ans += i.w;
		cnt++;
		if (cnt >= n - 1)
			break;
	}
	return ans;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
  	int u, v, w;
  	cin >> u >> v >> w;
  	E.push_back({u, v, w});
	}
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
			cin >> a[j][i];
	cout << kruskal() << endl;
  return 0;
}


