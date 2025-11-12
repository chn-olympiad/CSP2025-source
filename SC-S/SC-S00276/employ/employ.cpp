#include <bits/stdc++.h>

using namespace std;

typedef long long lnt;

const int N = 507, M = 998244353;

int n, m;
string s;
int c[N];

namespace u1 {
	int f[1 << 18][21];
	
	inline void Add(int &x, int y) {
		if ((x += y) >= M) {
			x -= M;
		}
	}
	
	void solve() {
		for (int i = 0; i < n; ++ i) {
			cin >> c[i];
		}
		f[0][0] = 1;
		int all = 1 << n;
		for (int S = 1; S < all; ++ S) {
			int e = 0;
			for (int i = 0; i < n; ++ i) {
				if (S >> i & 1) {
					++ e;
				}
			}
			for (int i = 0; i < n; ++ i) {
				if (S >> i & 1) {
					for (int j = 0; j < e; ++ j) {
						if (s[e] == '0' || c[i] <= e - 1 - j) {
							Add(f[S][j]    , f[S ^ (1 << i)][j]);
						} else {
							Add(f[S][j + 1], f[S ^ (1 << i)][j]);
						}
					}
				}
			}
		}
		int ans = 0;
		for (int j = m; j <= n; ++ j) {
			Add(ans, f[all - 1][j]);
		}
		cout << ans << '\n';
	}
}

void INIT() { }

void WORK() {
	cin >> n >> m >> s;
	s = ' ' + s;
	if (n <= 18) {
		u1::solve();
		return;
	}
	for (int i = 1; i <= n; ++ i) {
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
}

#define filename "employ"

int main() {
	#ifdef filename
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Turn = 1;
//	cin >> Turn;
	INIT();
	while (Turn -- ) {
		WORK();
	}
	return 0;
}