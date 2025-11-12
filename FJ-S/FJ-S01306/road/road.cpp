// long long !!!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10020, M = 1000010;

int n, m, k;
int u[M], v[M], w[M];
int c[20], a[20][N];
vector <pair <int, int>> edge[N];
int dp[N];
bool b[N];
set <pair <int, int>> s;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("road3.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1 ; i <= m ; i++)
		scanf("%d%d%d", &u[i], &v[i], &w[i]),
		edge[u[i]].push_back({v[i], w[i]}),
		edge[v[i]].push_back({u[i], w[i]});
	bool flaga = true;
	for (int i = 1 ; i <= k ; i++) {
		scanf("%d", &c[i]);
		flaga &= !c[i];
		for (int j = 1 ; j <= n ; j++)
			scanf("%d", &a[i][j]);
	}
	if (flaga) {
		ll ans = 0;
		for (int i = 1 ; i <= m ; i++)
			edge[u[i]].push_back({v[i], w[i]}),
			edge[v[i]].push_back({u[i], w[i]});
		for (int i = 1 ; i <= k ; i++)
			for (int j = 1 ; j <= n ; j++)
				edge[i + n].push_back({j, a[i][j]}),
				edge[j].push_back({i + n, a[i][j]});
		s.clear();
		dp[1] = 0, b[1] = false;
		s.insert({dp[1], 1});
		for (int i = 2 ; i <= n + k ; i++)
			dp[i] = 2e9, s.insert({dp[i], i}), b[i] = false;
		while (!s.empty()) {
			int x = s.begin() -> second;
			s.erase(s.begin());
			ans += dp[x], b[x] = true;
			for (auto y : edge[x])
				if (!b[y.first] && dp[y.first] > y.second) {
					s.erase({dp[y.first], y.first});
					dp[y.first] = y.second;
					s.insert({y.second, y.first});
				}
		}
		printf("%lld\n", ans);
//		cout << clock() << endl;
		return 0;
	}
	ll ans = 1LL << 62;
	for (int S = 0 ; S < (1 << (min(k, 5))) ; S++) {
		ll res = 0;
		int idx = n;
		vector <int> pos;
		for (int i = 0 ; i < k ; i++)
			if (S & (1 << i))
				++idx, res += c[i + 1], pos.push_back(i + 1);
		s.clear();
		dp[1] = 0, b[1] = false;
		s.insert({dp[1], 1});
		for (int i = 2 ; i <= idx ; i++)
			dp[i] = 2e9, s.insert({dp[i], i}), b[i] = false;
		while (!s.empty()) {
			int x = s.begin() -> second;
			if (dp[x] == 2e9) {
				res = 1LL << 62;
				break;
			}
			s.erase(s.begin());
			res += dp[x], b[x] = true;
			if (x <= n) {
				for (auto y : edge[x])
					if (!b[y.first] && dp[y.first] > y.second) {
						s.erase({dp[y.first], y.first});
						dp[y.first] = y.second;
						s.insert({y.second, y.first});
					}
				for (int y = 0 ; y < (int)pos.size() ; y++)
					if (!b[y + n + 1] && dp[y + n + 1] > a[pos[y]][x]) {
						s.erase({dp[y + n + 1], y + n + 1});
						dp[y + n + 1] = a[pos[y]][x];
						s.insert({a[pos[y]][x], y + n + 1});
					}
			} else {
				for (int i = 1 ; i <= n ; i++)
					if (!b[i] && dp[i] > a[pos[x - n - 1]][i]) {
						s.erase({dp[i], i});
						dp[i] = a[pos[x - n - 1]][i];
						s.insert({dp[i], i});
					}
			}
		}
		ans = min(ans, res);
//		cout << res << endl;
	}
	printf("%lld\n", ans);
//	cout << clock() << endl;
	return 0;
}
