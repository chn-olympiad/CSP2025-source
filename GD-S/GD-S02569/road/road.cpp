#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 40;
int n, m, k, ans = numeric_limits<int>::max();
vector<array<int, 3>> edge;
int w[12][N];
int fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void del() {
	vector<array<int, 3>> tmp;
	sort(edge.begin(), edge.end(), [](const array<int, 3>& x, const array<int, 3>& y) -> bool { return x[2] < y[2]; });
	iota(fa + 1, fa + n + 1, 1);
	int cnt = 0;
	for (const auto& now : edge) {
		if (find(now[0]) == find(now[1]))
			continue;
		fa[find(now[0])] = find(now[1]);
		cnt++;
		tmp.emplace_back(now);
		if (cnt == n - 1)
			break;
	}
	swap(tmp, edge);
}

inline int sol(int sta) {
	int c = n, res = 0;
	for (int i = 1, t = sta; t; i++, t >>= 1) {
		if (t & 1) {
			c++;
			res += w[i][0];
		}
	}
	iota(fa + 1, fa + n + k + 1, 1);
	int cnt = 0;
	for (const auto& now : edge) {
		if (now[0] > n && !((sta >> now[0] - n - 1) & 1))
			continue;
		int f1 = find(now[0]), f2 = find(now[1]);
		if (f1 == f2)
			continue;
		fa[f1] = f2;
		cnt++;
		res += now[2];
		if (res >= ans)
			return res;
		if (cnt == c)
			break;
	}
	// cout << res << '\n';
	return res;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	edge.assign(m, array<int, 3>());
	for (auto& i : edge)
		for (int& j : i)
			cin >> j;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			cin >> w[i][j];
	del();
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			edge.push_back({n + i, j, w[i][j]});
	sort(edge.begin(), edge.end(), [](const array<int, 3>& x, const array<int, 3>& y) -> bool { return x[2] < y[2]; });
	for (int i = 0; i < (1 << k); i++)
		ans = min(ans, sol(i));
	cout << ans;
}