#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pii pair< int, int >
#define inf 0x3f3f3f3f3f3f3f3f
#define F(v, x) for (auto v : (x))
#define ALL(x) (x).begin(), (x).end()
#define L(i, a, b) for (int i = (a); i <= (b); i++)
#define R(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
bool bm;

inline void cmin(int &x, int c) { x = min(x, c); }
inline void cmax(int &x, int c) { x = max(x, c); }

int tes = 1, cas;

namespace zrh {
	const int N = 505, P = 998244353;
	int n, m, a[N], c[N], cnt;
	bool vis[N];
	string s;
	void dfs(int u) {
		if (u == n + 1) {
			int d = 0;
			L(i, 1, n) if (i - 1 - d < a[c[i]] && s[i] == '1') d++;
			cnt += (d >= m);
			return;
		}
		L(i, 1, n) if (!vis[i]) {
			vis[i] = 1, c[u] = i;
			dfs(u + 1);
			vis[i] = 0, c[u] = 0;
		}
	}
	void init() {}
	void clear() {}
	void solve() {
		cin >> n >> m; 
		cin >> s, s = " " + s;
		L(i, 1, n) cin >> a[i];
		dfs(1);
		cout << cnt % P << "\n";
	}
}

bool em;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> tes;
	zrh::init(); while (++cas <= tes) zrh::clear(), zrh::solve();
//	cerr << "time  : " << (double)clock() / CLOCKS_PER_SEC * 1000 << "ms\n";
//	cerr << "memory: " << fabs(&bm - &em) / 1024 / 1024 << "mb\n";
	return 0;
}
// I love zrh forever.

