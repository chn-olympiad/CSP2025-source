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
	
	bool Check (string a, int id, string b) {
		for (register int i = 0; i ^ b.size (); ++ i) {
			if (i + id >= a.size () || a[i + id] ^ b[i]) {
				return 0;
			}
		}
		
		return 1;
	}
	
	string th (string a, int id, string b) {
		for (register int i = 0; i ^ b.size (); ++ i) {
			a[i + id] = b[i];
		}
		
		return a;
	}
	
	int Get (string x) {
		int ans = -1;
		
		for (register int i = 0; i ^ x.size (); ++ i) {
			if (x[i] == 'a') {
				continue ;
			} else if (x[i] == 'b') {
				if (~ ans) {
					return -1;
				} else {
					ans = i;
				}
			}
		}
		
		return ans;
	}
	
	const int N = 2e5 + 5;
	
	int n, q;
	string s[N][2];
	string t1, t2;
	int _Ans;
	vector <pair <int, int>> a[N << 1];
	bool _Flgb;
	int _, __;

	void Main () {
		_Flgb = 1;
		cin >> n >> q;
		
		for (register int i = 1; i <= n; ++ i) {
			cin >> s[i][0] >> s[i][1];
			
			if (_Flgb) {
				_ = Get (s[i][0]);
				__ = Get (s[i][1]);
				
				if (! (~ _ && ~ __)) {
					_Flgb = 0;
					cerr << i << ' ' << _ << ' ' << __ << endl;
					continue ;
				}
				
				a[N + __ - _].push_back ({min (_, __), s[i][0].size () - max (_, __)});
			}
		}
		
//		cerr << _Flgb << endl;
//		
		while (q --) {
			_Ans = 0;
			cin >> t1 >> t2;
			
			if (_Flgb && ~ Get (t1) && ~ Get (t2)) {
				_ = Get (t1);
				__ = Get (t2);
				
				for (auto it : a[N + __ - _]) {
					if (min (_, __) >= it.first && it.second + max (_, __) <= t1.size ()) {
						++ _Ans;
					}
				}
			} else {
				for (register int i = 1; i <= n; ++ i) {
					for (register int j = 0; j < t1.size (); ++ j) {
						if (Check (t1, j, s[i][0]) && th (t1, j, s[i][1]) == t2) {
							++ _Ans;
						}
					}
				}
			}
			
			cout << _Ans << endl;
		}
	}
}

signed main () {
	cin.tie (nullptr) -> ios :: sync_with_stdio (false);
	
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	int T = 1;
	//WTH :: input (T);

	while (T --) {
		WTH :: Main ();
	}

	return 0;
}

