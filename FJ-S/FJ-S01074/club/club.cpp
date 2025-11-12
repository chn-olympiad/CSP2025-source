#include <bits/stdc++.h>
#define sp " "
#define el "\n"
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef string str;

int t;
int n;
int a[110000][5];
int id[110000][5];
std::vector<int> v[5];
std::vector<std::pair<int, int>> c;
int f[110000];
int ans;
int q = 0, w = 0, e = 0;

inline void dfs(int x) {
	if (x == n + 1) {
		if (std::max({q, w, e}) <= n / 2) {
			int cnt = 0;
			F(i, 1, n, 1) {
				cnt += a[i][f[i]];
			}
			ans = std::max(ans, cnt);
		}
		return;
	}
	F(i, 1, 3, 1) {
		if (i == 1 && q + 1 <= n / 2) {
			f[x] = i;
			q++;
			dfs(x + 1);
			q--;
		}
		if (i == 2 && w + 1 <= n / 2) {
			f[x] = i;
			w++;
			dfs(x + 1);
			w--;
		}
		if (i == 3 && e + 1 <= n / 2) {
			f[x] = i;
			e++;
			dfs(x + 1);
			e--;
		}
	}
}

signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		F(i, 1, n, 1) {
			F(j, 1, 3, 1) {
				cin >> a[i][j];
			}
		}
		F(i, 1, n, 1) {
			int ma = std::max({a[i][1], a[i][2], a[i][3]});
			int mi = std::min({a[i][1], a[i][2], a[i][3]});
			int md = a[i][1] + a[i][2] + a[i][3] - ma - mi;
			if (ma == a[i][1]) {
				id[i][1] = 1;
			} else {
				if (ma == a[i][2]) {
					id[i][1] = 2;
				} else {
					id[i][1] = 3;
				}
			}
			if (md == a[i][1]) {
				id[i][2] = 1;
			} else {
				if (md == a[i][2]) {
					id[i][2] = 2;
				} else {
					id[i][2] = 3;
				}
			}
			if (mi == a[i][1]) {
				id[i][3] = 1;
			} else {
				if (mi == a[i][2]) {
					id[i][3] = 2;
				} else {
					id[i][3] = 3;
				}
			}
		}/*
		c.clear();
		F(i, 1, n, 1) {
			c.push_back({a[i][id[i][1]] - a[i][id[i][2]], i});
		}
		std::sort(c.begin(), c.end());
		F(j, 0, c.size() - 1, 1) {
			cout << c[j].se << el;
		}*/
		F(i, 1, 3, 1) {
			v[i].clear();
		}
		F(i, 1, n, 1) {
			v[id[i][1]].push_back(i);
		}
		if (std::max({v[1].size(), v[2].size(), v[3].size()}) <= n / 2) {
			ans = 0;
			F(i, 1, n, 1) {
				ans += a[i][id[i][1]];
			}
			cout << ans << el;
			continue;
		}/*
		if (n <= 10) {
			ans = 0;
			q = w = e = 0;
			dfs(1);
			cout << ans << el;
			continue;
		}*/
		F(i, 1, 3, 1) {
			if (v[i].size() > n / 2) {
				int m = v[i].size();
				c.clear();
				F(j, 0, m - 1, 1) {
					c.push_back({abs(a[v[i][j]][id[v[i][j]][1]] - a[v[i][j]][id[v[i][j]][2]]), v[i][j]});
				}
				std::sort(c.begin(), c.end(), std::greater<std::pair<int, int>>());
				F(j, 0, m - 1, 1) {
					v[i][j] = c[j].se;
				}
				while (v[i].size() > n / 2) {
					int x = v[i].back();
					v[i].pop_back();
					v[id[x][2]].push_back(x);
					//cerr << i << sp << v[i].size() << sp << x << sp << id[x][2] << el;
				}
				break;
			}
		}
		ans = 0;
		F(i, 1, 3, 1) {
			int mm = v[i].size();
			F(j, 0, mm - 1, 1) {
				ans += a[v[i][j]][i];
			}
		}
		cout << ans << el;
	}
	r0;
}