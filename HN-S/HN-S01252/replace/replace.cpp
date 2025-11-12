#include <bits/stdc++.h>
//#define int long long
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

using ull = unsigned long long;
const int N = 2e5, L = 5e6, base = 131;
int n, q, len [N + 5];
ull hashs [N + 5], hasht [N + 5], basepow [L + 5];
ull hashqs [L + 5], hashqt [L + 5];
char s [L + 5], t [L + 5];
ull qpow (int x, int n) {
	ull res = 1;
	while (n) {
		if (n & 1) {
			res *= x;
			
		}
		n >>= 1;
		x *= x;
	}
}
void Turn () {
	cin >> n >> q;
	basepow [0] = 1;
	for (int i = 1 ; i <= L ; i ++) basepow [i] = basepow [i - 1] * base;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> (s + 1) >> (t + 1);
		len [i] = strlen (s + 1);
		for (int i = 1 ; i <= n ; i ++) {
			hashs [i] = hashs [i - 1] * base + s [i];
			hasht [i] = hasht [i - 1] * base + t [i];
		}
	}
	
	for (int i = 1 ; i <= q ; i ++) {
		cin >> (s + 1) >> (t + 1);
		int m = strlen (s + 1);
		for (int i = 1 ; i <= m ; i ++) {

		} cout << 0 << endl;
	}
}

int _; void Init () {
//	ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
	_ = 1;
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
//	cin >> _;
}

	signed main () { Init ();
	while (_ --> 0) 
	Turn (); return 0; }
