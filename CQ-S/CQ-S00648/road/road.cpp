#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int> 
typedef long long ll;
struct node {
	ll u, v, w, flag;
};
vector<node> v;
int fa[10010];
ll c[20], num[20];
ll a[20][10010];
inline int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}
inline bool cmp(node a, node b) {
	return a.w < b.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, V, w;
		cin >> u >> V >> w;
		v.push_back({u, V, w, 0});
		v.push_back({V, u, w, 0});
	}
	if (k == 0) {
		//最小生成树 
		sort(v.begin(), v.end(), cmp);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		ll ans = 0, cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].u, y = v[i].v;
			int p = find(x), q = find(y);
			if (p ^ q) {
				ans += v[i].w;
				cnt++;
				fa[p] = q;
			}
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		ll p = 0;
		for (int j = 1; j <= n; j++) {
			for (int l = j + 1; l <= n; l++) {
				p = a[i][j] + a[i][l] + c[i];
				v.push_back({j, l, p, i});
				v.push_back({l, j, p, i});
			}
		}
	}
		//最小生成树 
		sort(v.begin(), v.end(), cmp);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		ll ans = 0, cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].u, y = v[i].v;
			int p = find(x), q = find(y);
			if (p ^ q) {
				ans += v[i].w;
				num[v[i].flag]++;
				cnt++;
				fa[p] = q;
			}
			if (cnt == n - 1) {
				break;
			}
		}
		for (int i = 1; i <= k; i++) {
			if (num[i] > 0) {
				ans -= c[i] * (num[i] - 1);
			}
		}
		cout << ans;
		return 0;
	return 0;
}

