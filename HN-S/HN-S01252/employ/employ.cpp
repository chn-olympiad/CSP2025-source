#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T> void _p (T x) { cout << x << ", "; }
template <typename T, typename ...R> void _p (T x, R ...r) { _p (x); _p (r...); }
template <typename ...R> void _d (const char *s, R ...r) {
	cout << s << ": "; _p (r...); cout << endl;
}
template <typename T> void _r (const char *s, T x, int n) {
	cout << s << ": {";
	for (int i = 1 ; i < n ; i ++) _p (x [i]);
	cout << x [n] << "}\n";
}
#define debug(...) _d (#__VA_ARGS__, __VA_ARGS__)
#define debua(a,n) _r (#a, a, n);

const int N = 500, mod = 998244353;
int n, m, c [N + 5], p [N + 5], ans = 0;
char s [N + 5];
int flag [N + 5];

void dfs (int u) {
	if (u > n) {
		int res = 0, k = 0;
		for (int i = 1 ; i <= n ; i ++) {
			if (s [i] == '0' || k >= c [p [i]]) {
				k ++;
			} else {
				res ++;
			}
		}
		if (res >= m) {
			ans ++;
		}
		ans %= mod;
		
		return ;
	}
	
	for (int i = 1 ; i <= n ; i ++) {
		if (!flag [i]) {
			flag [i] = 1; p [u] = i;
			dfs (u + 1);
			flag [i] = 0;
		}
	}
}

void Turn () {
	cin >> n >> m >> (s + 1);
	int A = 1;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> c [i];
		if (s [i] != '1') A = 0;
	}
	
	if (A) {
		int ans = 1; int tot = 0;
		for (int i = 1 ; i <= n ; i ++) {
			if (c [i] != 0) {
				tot ++;
			}
		} 
		if (tot < m) {
			cout << 0 << endl;
			return ;
		}
		
		for (int i = tot + 1 ; i <= n ; i ++) {
			ans *= i;
			ans %= mod;
		} cout << ans << endl;
		
		return ;
	}
	
	dfs (1);
	cout << ans << endl;
}

int _; void Init () {
//	ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
	_ = 1;
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
//	cin >> _;
}

	signed main () { Init ();
	while (_ --> 0) 
	Turn (); return 0; }
