#include <bits/stdc++.h>

#define endl '\n'
#define int long long
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
	
	const int N = 1e5 + 5;
	
	int n;
	int a[N][5];
	int d[N];
	int cnt[5];
	int jian[N], jiancnt;
	int _, __;
	int _Ans;

	void Main () {
		input (n);
		_Ans = 0;
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		jiancnt = 0;
		
		for (register int i = 1; i <= n; ++ i) {
			for (register int j = 1; j <= 3; ++ j) {
				input (a[i][j]);
			}
			
			__ = 0;
			
			for (register int j = 1; j <= 3; ++ j) {
				if (a[i][j] > __) {
					_ = j;
					__ = a[i][j];
				}
			}
			
//			cout << i << ' ' << _ << ' ' << __ << endl;
			d[i] = _;
			_Ans += __;
			++ cnt[_];
		}
		
//		for (register int i = 1; i <= n; ++ i) {
//			cout << d[i] << ' ' << a[i][d[i]] << endl;
//		}
//		
//		exit (-1);
//		
		if (cnt[1] > (n >> 1)) {
			for (register int i = 1; i <= n; ++ i) {
				if (d[i] == 1) {
					jian[++ jiancnt] = a[i][1] - max (a[i][2], a[i][3]);
				}
			}
			
			sort (jian + 1, jian + jiancnt + 1);
			
			for (register int i = 1; i <= (cnt[1] - (n >> 1)); ++ i) {
				_Ans -= jian[i];
			}
		} else if (cnt[2] > (n >> 1)) {
			for (register int i = 1; i <= n; ++ i) {
				if (d[i] == 2) {
					jian[++ jiancnt] = a[i][2] - max (a[i][1], a[i][3]);
				}
			}
			
			sort (jian + 1, jian + jiancnt + 1);
			
			for (register int i = 1; i <= (cnt[2] - (n >> 1)); ++ i) {
				_Ans -= jian[i];
			}
		} else if (cnt[3] > (n >> 1)) {
			for (register int i = 1; i <= n; ++ i) {
				if (d[i] == 3) {
					jian[++ jiancnt] = a[i][3] - max (a[i][1], a[i][2]);
				}
			}
			
			sort (jian + 1, jian + jiancnt + 1);
			
			for (register int i = 1; i <= (cnt[3] - (n >> 1)); ++ i) {
				_Ans -= jian[i];
//				cout << jian[i] << endl;
			}
		}
		
		output (_Ans);
		putchar ('\n');
	}
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	int T = 1;
	WTH :: input (T);

	while (T --) {
		WTH :: Main ();
	}

	return 0;
}

