#include <bits/stdc++.h>
using namespace std;
struct road {
	int u, v, w;
};
vector<road> roads;
long long ans;
int pa[10010], cnt;
int myfind(int x) {
	if (x == pa[x]) {
		return x;
	}	
	return pa[x] = myfind(pa[x]);
}
bool cmp(road a, road b) {
	return a.w <= b.w;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w, a;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		roads.push_back((road){u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> a;
		for (int i = 1; i <= n; i++) {
			cin >> w;
		}
	}
	sort(roads.begin(), roads.end(), cmp);
	for (int i = 1; i <= n; i++) {
		pa[i] = i;
	}
	for (road i : roads) {
		u = i.u; v = i.v;
		if (myfind(u) != myfind(v)) {
			pa[v] = myfind(u);
			ans += i.w;
			cnt++;
			if (cnt == n - 1) {
				cout << ans << endl;
				return 0;
			}
		}
	}
}
