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

const int N = 1e5;
struct Node {
	int a, b, c;
} a [N + 5];

int n, sx, sy, sz, ans, tag [N + 5];
priority_queue <pair <int, int> > q;

void Turn () { ans = sx = sy = sz = 0;	
	while (!q. empty ()) q. pop ();
	memset (tag, 0, sizeof tag);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x > y) {
			if (x > z) {
				sx ++;
			} else {
				sz ++;
			}
		} else {
			if (y > z) {
				sy ++;
			} else {
				sz ++;
			}
		} ans += max ({x, y, z});
		a [i] = {x, y, z};
	}
	
	if (sx <= n / 2 && sy <= n / 2 && sz <= n / 2) {
		cout << ans << endl;
		return ;
	}
	
	if (sy > n / 2) {
		for (int i = 1 ; i <= n ; i ++) {
			swap (a [i]. a, a [i]. b);
		} swap (sx, sy);
	}
	
	if (sz > n / 2) {
		for (int i = 1 ; i <= n ; i ++) {
			swap (a [i]. a, a [i]. c);
		} swap (sx, sz);
	}
	
	for (int i = 1 ; i <= n ; i ++) {
		if (a [i]. a > a [i]. b && a [i]. a > a [i]. c) {
			q. push ({a [i]. b - a [i]. a, i});
			q. push ({a [i]. c - a [i]. a, i});
		}
	}
	int changes = sx - n / 2;
	for (int j = 1 ; j <= changes ; j ++) {
		while (tag [q. top (). second]) q. pop ();
		int u = q. top (). first, i = q. top (). second;
		tag [i] = 1; ans += u;
	}
	
	cout << ans << endl;
}

int _; void Init () {
	ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
	_ = 1;
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> _;
}

	signed main () { Init ();
	while (_ --> 0) 
	Turn (); return 0; }
	
// 8£º17 accepts 
