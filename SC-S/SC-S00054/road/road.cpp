#include<bits/stdc++.h>

#define rep(i, s, e) for(int (i) = (s); (i) <= (e); ++(i))
#define fep(i, s, e) for(int (i) = (s); (i) < (e); ++(i))
#define _rep(i, s, e) for(int (i) = (s); (i) >= (e); --(i))
#define _fep(i, s, e) for(int (i) = (s); (i) > (e); --(i))

#define int long long
#define pii pair<int, int>

using namespace std;

constexpr int inf = numeric_limits<int>::max() / 2;
constexpr int ninf = numeric_limits<int>::min() / 2;
constexpr int mod = 998244353;
constexpr double eps = 1e-9;

int n, m, k, c[11], a[11][10005], cnt, num, sum, ans, flag, tmp;
tuple<int, int, int> e1[1000005], e2[1100005];

struct DSU {
	int fa[10015], cst, cnt;
	void init(int n) {
		rep(i, 1, n) {
			fa[i] = i;
		}
		cst = 0;
		cnt = 0;
		return;
	}
	int findfa(int x) {
		return fa[x] == x ? x : fa[x] = findfa(fa[x]);
	}
	void merge(int x, int y, int z) {
		x = findfa(x);
		y = findfa(y);
		if(x != y) {
			fa[x] = y;
			cst += z;
			++cnt;
		}
		return;
	}
} dsu;

void solve() {
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		e1[i] = (tuple<int, int, int>){u, v, w};
	}
	flag = 1;
	rep(i, 1, k) {
		cin >> c[i];
		flag = flag and (not c[i]);
		tmp = 0;
		rep(j, 1, n) {
			cin >> a[i][j];
			tmp = tmp or (not a[i][j]);
		}
		flag = flag and tmp;
	}
	ans = inf;
	fep(st, 0, 1 << k) {
		if(flag) st = (1 << k) - 1;
		rep(j, 1, m) {
			e2[j] = e1[j];
		}
		sum = 0;
		num = n;
		cnt = m;
		rep(i, 1, k) {
			if((st >> (i - 1)) & 1) {
				++num;
				sum += c[i];
				rep(j, 1, n) {
					e2[cnt + j] = (tuple<int, int, int>){num, j, a[i][j]};
				}
				cnt += n;
			}
		}
		sort(e2 + 1, e2 + 1 + cnt, [](tuple<int, int, int> a, tuple<int, int, int> b) {
			return get<2>(a) < get<2>(b);
		});
		dsu.init(num);
		rep(i, 1, cnt) {
			int u, v, w;
			tie(u, v, w) = e2[i];
			dsu.merge(u, v, w);
			if(dsu.cnt == num - 1) {
				break;
			}
		}
		ans = min(ans, sum + dsu.cst);
	}
	cout << ans << endl;
	return;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}