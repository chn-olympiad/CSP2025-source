#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define lnf 0x3f3f3f3f3f3f3f3f

using namespace std;

namespace WTH {
	inline void input (int & x) {
		x = 0;
		char c = getchar ();

		while (! isdigit (c)) {
			c = getchar ();
		}

		while (isdigit (c)) {
			x = (x << 3) + (x << 1) + (c ^ 48);
			c = getchar ();
		}
	}

	inline void output (int x) {
		char cnt = 0, _Wrt[25];

		do {
			_Wrt[++ cnt] = x % 10;
			x /= 10;
		} while (x);

		do {
			putchar (_Wrt[cnt] | 48);
			-- cnt;
		} while (cnt);
	}
	
	char gc () {
		char c = getchar ();
		
		while (! isdigit (c)) {
			c = getchar ();
		}
		
		return c;
	}
	
	int KSM (int a, int b = mod - 2, int mo = mod) {
		int ans = 1;
		
		while (b) {
			if (b & 1) {
				ans *= a;
				ans %= mod;
			}
			
			a *= a;
			a %= mod;
			b >>= 1;
		}
		
		return ans;
	}
	
	const int N = 10 + 5;
	
	int n, m;
	bool _Flg[N];
	int c[N];
	int _Ans;
	int _, __, ___;
	int ak;
	int xl[N];
	bool flg[N];
	
	void DFS (int id) {
		if (id > n) {
			_ = 0;
			__ = 0;
			
			for (register int i = 1; i <= n; ++ i) {
				if (_Flg[i] && __ < c[xl[i]]) {
					++ _;
				} else {
					++ __;
				}
			}
			
//			for (register int i = 1; i <= n; ++ i) {
//				cout << xl[i] << ' ';
//			}
//			
//			cout << _ << ' ' << __ << endl;
//			
			if (_ >= m) {
				++ _Ans;
			}
			
			return ;
		}
		
		for (register int i = 1; i <= n; ++ i) {
			if (! flg[i]) {
				flg[i] = 1;
				xl[id] = i;
				DFS (id + 1);
				flg[i] = 0;
			}
		}
	}

	void Main () {
		input (n);
		
		if (n > 10) {
			_Ans = 1;
			
			for (register int i = 1; i <= n; ++ i) {
				_Ans *= i;
				_Ans %= mod;
			}
			
			input (m);
			
			if (! m) {
				output (_Ans);
				return ;
			}
			
			for (register int i = 1; i <= n; ++ i) {
				gc ();
			}
			
			for (register int i = 1; i <= n; ++ i) {
				if (! c[i]) {
					output (0);
					return ;
				}
			}
		} else {
			input (m);
			
			for (register int i = 1; i <= n; ++ i) {
				_Flg[i] = gc () ^ 48;
			}
			
			for (register int i = 1; i <= n; ++ i) {
				input (c[i]);
			}
			
			DFS (1);
		}
		
		output (_Ans);
	}
}

signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	int T = 1;
	//WTH :: input (T);

	while (T --) {
		WTH :: Main ();
	}

	return 0;
}

