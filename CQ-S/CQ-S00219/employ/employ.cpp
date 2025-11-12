#include <bits/stdc++.h>
#define all(x) x.begin (), x.end ()
using namespace std;
using ll = long long;
using db = double;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;
const int mod = 998244353;

template <typename T>
void cmax (T &a, const T &b) {if (a < b) a = b;}
template <typename T>
void cmin (T &a, const T &b) {if (a > b) a = b;}

template <typename T>
ostream & operator << (ostream &os, vector <T> &a) {
	for (auto &v : a) os << v << ' ';
	return os;
}

namespace sub1 {
	int n, m;
	string a;
	vector <int> c;
	
	void solve () {
		vector <int> siz (1 << n, 0);
		for (int msk = 0; msk < (1 << n); msk++) for (int j = 0; j < n; j++) if (msk & (1 << j))
		siz[msk]++;
		
		vector <vector <vector <int>>> dp ((1 << n), vector <vector <int>> (n + 1, vector <int> (n + 2, 0)));
		dp[0][0][0] = 1;
		for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) if (!(i & (1 << j)))
			for (int x = siz[i]; x < n; x++) for (int y = 0; y <= siz[i]; y++) {
				if (c[j] <= siz[i] - y) dp[i | (1 << j)][x][y] = (dp[i | (1 << j)][x][y] + dp[i][x][y]) % mod;
				else if (a[x] == '0') dp[i | (1 << j)][x + 1][y] = (dp[i | (1 << j)][x + 1][y] + dp[i][x][y]) % mod;
				else if (a[x] == '1') dp[i | (1 << j)][x + 1][y + 1] = (dp[i | (1 << j)][x + 1][y + 1] + dp[i][x][y]) % mod;
			}
		
		ll ans = 0;
		for (int i = 1; i <= n; i++) for (int j = m; j <= n + 1; j++) ans = (ans + dp[(1 << n) - 1][i][j]) % mod;
		cout << ans << '\n';
	}
}

void init () {
	
}

void solve () {
	int n, m; cin >> n >> m;
	string a; cin >> a;
	vector <int> c (n, 0);
	for (auto &v : c) cin >> v;
	
	if (n <= 18) {
		sub1 :: n = n;
		sub1 :: m = m;
		sub1 :: a = move (a);
		sub1 :: c = move (c);
		sub1 :: solve ();
		return ;
	}
}

int main () {
#ifndef LOCAL
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
#endif
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	
	init ();
	
	int t = 1;
//	cin >> t;
	while (t--) solve ();
}
