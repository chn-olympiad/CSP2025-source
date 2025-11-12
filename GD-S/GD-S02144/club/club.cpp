#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define PII pair<int, int>
#define PLL pair<ll, ll>
using namespace std;

constexpr ll inf = (1ll << 62);
constexpr int N = 1e5 + 10;

int n;
int c[N];
ll ans;

struct Node {
	int x, y, z;
} a[N];

ll calc() {
	ll cnt1 = 0, cnt2 = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			res += a[i].x;
		} else if (c[i] == 1) {
			res += a[i].y;
			cnt1++;
		} else {
			res += a[i].z;
			cnt2++;
		}
	}
	if (cnt1 > n / 2 || cnt2 > n / 2 || n - cnt1 - cnt2 > n / 2) {
		return 0;
	}
	return res;
}

void dfs(int x) {
	if (x == n) {
		ans = max(ans, calc());
		return;
	}
	c[x] = 0;
	dfs(x + 1);
	c[x] = 1;
	dfs(x + 1);
	c[x] = 2;
	dfs(x + 1);
}

void solve() {
	cin >> n;
	vector<vector<PLL>> d(n);
	bool ok = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		d[i].push_back({a[i].x, 0});
		d[i].push_back({a[i].y, 1});
		d[i].push_back({a[i].z, 2});
		d[i].push_back({0, -1});
	}
//	f[0][1][0] = a[0].x;
//	f[0][0][1] = a[0].y;
//	f[0][0][0] = a[0].z;
//	ll ans = 0;
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j <= i / 2 + 1; j++) {
//			for (int k = i / 2 + 1; i + 1 - j - k <= i / 2 + 1 && k >= 0; k--) {
//				if (j + k > i + 1) continue;
//				if (j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i].x);
//				if (k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i].y);
//				if (j + k < i + 1) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i].z);
////				f[i][j][k] = max({f[i - 1][j - 1][k] + a[i].x, f[i - 1][j][k - 1] + a[i].y, f[i - 1][j][k] + a[i].z});
//				ans = max(ans, f[i][j][k]);
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= n; j++) {
//			for (int k = 0; k <= n; k++) {
////				cout << i << " " << j << " " << k << ": " << f[i][j][k] << "\n";
//				f[i][j][k] = 0;
//			}
//		}
//	}
	ans = 0;
//	dfs(0);
	priority_queue<pair<PLL, PLL>, vector<pair<PLL, PLL>>, greater<pair<PLL, PLL>>> q[3];
	for (int i = 0; i < n; i++) {
		sort(d[i].begin(), d[i].end(), [&](PLL a, PLL b) {
			return a.first > b.first;
		});
		for (int j = 0; j < 3; j++) {
			int val = d[i][j].first, id = d[i][j].second;
			if (q[id].size() < n / 2) {
				ans += val;
				q[id].push({{val - d[i][j + 1].first, d[i][j + 1].second}, {val, i}});
//				cout << i << " " << val - d[i][j + 1].first << " " << id << " !\n";
				break;
			}
			int lst = q[id].top().second.second, val1 = q[id].top().second.first, maxn = val1 - q[id].top().first.first, id1 = q[id].top().first.second;
//			if (i == 4) {
//				cout << lst << " " << ans << " " << d[i][j + 1].first << " " << val << " " << q[id].top().second.first << " " << maxn << "\n";
//			}
			if (ans + d[i][j + 1].first < ans + val - q[id].top().second.first + maxn) {
//				cout << "cinema\n";
				for (int k = 0; k < 3; k++) {
					if (maxn == d[lst][k].first) {
						q[id1].push({{maxn - d[lst][k + 1].first, d[lst][k + 1].second}, {maxn, lst}});
						break;
					}
				}
				ans -= q[id].top().second.first;
//				cout << lst << " " << id1 << "\n";
				ans += maxn;
				q[id].pop();
				ans += val;
//				cout << i << " " << id << "\n";
				q[id].push({{val - d[i][j + 1].first, d[i][j + 1].second}, {val, i}});
				break;
			}
		}
	}
//	for (int i = 0; i < 3; i++) {
//		while (!q[i].empty()) {
//			ans += q[i].top().first;
//			q[i].pop();
//		}
//	} 
	cout << ans << "\n";
}
/*
很 dp 的感觉……
贪心就很假
dp 的状态和转移是显然的，那如何优化呢？n^3 级别的很难搞，感觉还是转换加贪心 
想到一个思路，按 a[i].x 从大到小排序，然后预处理出在 i~n 中选出 a[i].y 和 a[i].z 的最大值能为多少
接着枚举 a[i].x，取最大值即可 
observation:
1. 可以直接从 i-2 的地方转移而来，这样无论如何都不会超过 i / 2，但怎样处理取 i, i-1 的情况 

会不会是反悔贪心？很像哎 还真是！！！！！ 

1
4
7 9 7
1 8 1
7 1 1
3 6 5

1
6
3 7 3
7 7 5
10 9 4
10 6 10
8 1 5
9 6 8

1
4
10 4 0
4 1 0
1 3 0
5 7 0
*/

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
