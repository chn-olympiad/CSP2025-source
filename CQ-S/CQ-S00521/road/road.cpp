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
	
	template <size_t _Sz>
		class BCJ {
			private :
				int fa[_Sz];
			
			protected :
			
			public :
				void Reset () {
					for (register int i = 0; i < _Sz; ++ i) {
						fa[i] = 0;
					}
				}
				
				int Get (int x) {
					if (fa[x]) {
						return fa[x] = Get (fa[x]);
					}
					
					return x;
				}
				
				void Merge (int x, int y) {
					if (Get (x) ^ Get (y)) {
						fa[Get (x)] = Get (y);
					}
				}
			
		} ;
	
	const int N = 1e4 + 25, M = 1e6 + 5;
	
	int n, m, k;
	pair <int, pair <int, int>> e[M];
	int c[15][N];
	int _Ths, ths;
	int _Ans;
	BCJ <N> _Flg;
	pair <int, pair <int, int>> E[M];
	int cnt;
	pair <int, pair <int, int>> _;
	int I, J;
	int ___;

	void Main () {
		_Ans = lnf;
		input (n);
		input (m);
		input (k);
		
		for (register int i = 1; i <= m; ++ i) {
			input (e[i].second.first);
			input (e[i].second.second);
			input (e[i].first);
		}
		
		sort (e + 1, e + m + 1);
		
		for (register int i = 1; i <= k; ++ i) {
			for (register int j = 0; j <= n; ++ j) {
				input (c[i][j]);
			}
		}
		
		for (register int i = 0; i ^ (1 << k); ++ i) {
			_Flg.Reset ();
			___ = 0;
			_Ths = 0;
			ths = 0;
			cnt = 0;
			I = 1;
			J = 1;
			
			for (register int j = 1; j <= k; ++ j) {
				if ((i >> (j - 1)) & 1) {
					++ ___;
					_Ths += c[j][0];
					
					for (register int K = 1; K <= n; ++ K) {
						E[++ cnt] = {c[j][K], {j + n, K}};
					}
				}
			}
			
			___ += n;
			
			sort (E + 1, E + cnt + 1);
			
			while (I <= m && J <= cnt && ths < ___ - 1) {
				if (e[I] < E[J]) {
					_ = e[I];
					++ I;
				} else {
					_ = E[J];
					++ J;
				}
				
				if (_Flg.Get (_.second.first) ^ _Flg.Get (_.second.second)) {
//					cout << _.first << ' ' << _.second.first << ' ' << _.second.second << endl;
					_Ths += _.first;
					++ ths;
					_Flg.Merge (_.second.first, _.second.second);
				}
			}
			
			if (ths < n - 1) {
				while (I <= m && ths < ___ - 1) {
					_ = e[I];
					++ I;
					
					if (_Flg.Get (_.second.first) ^ _Flg.Get (_.second.second)) {
//						cout << _.first << ' ' << _.second.first << ' ' << _.second.second << endl;
						_Ths += _.first;
						++ ths;
						_Flg.Merge (_.second.first, _.second.second);
					}
				}
				
				while (J < cnt && ths < ___ - 1) {
					_ = E[J];
					++ J;
					
					if (_Flg.Get (_.second.first) ^ _Flg.Get (_.second.second)) {
//						cout << _.first << ' ' << _.second.first << ' ' << _.second.second << endl;
						_Ths += _.first;
						++ ths;
						_Flg.Merge (_.second.first, _.second.second);
					}
				}
			}
			
			_Ans = min (_Ans, _Ths);
//			cout << _Ths << endl << endl;
		}
		
//		cerr << _Ans;
		output (_Ans);
		putchar ('\n');
	}
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	int T = 1;
	//WTH :: input (T);

	while (T --) {
		WTH :: Main ();
	}

	return 0;
}

