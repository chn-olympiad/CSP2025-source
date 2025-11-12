// 20pts
#include<bits/stdc++.h>
using namespace std;

const int kMaxN = 500 + 5, kM = 998244353, kS = 1 << 18;

int n, m, subA = 1, s[kMaxN], p[kMaxN], c[kMaxN], f[kS][20];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		s[i] = (ch == '1');
		subA &= s[i];
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	int ans = 0;
	if(n <= 10) {
		for(int i = 1; i <= n; i++) {
			p[i] = i;
		}
		do {
			int gg = 0, cnt = 0;
			for(int i = 1; i <= n; i++) {
				if(s[i] && gg < c[p[i]]) {
					++cnt;
				} else {
					++gg;
				}
			}
			ans = (ans + (cnt >= m)) % kM;
		} while(next_permutation(p + 1, p + n + 1));
		cout << ans << '\n';
	} else {
		f[0][0] = 1;
		for(int S = 0; S < (1 << n); S++) {
			for(int i = 1; i <= n; i++) {
				if(S >> (i - 1) & 1) continue;
				int x = __builtin_popcount(S);
				for(int j = 0; j <= x; j++) {
					if(s[x + 1] && j < c[i]) {
						f[S | (1 << (i - 1))][j] = (f[S | (1 << (i - 1))][j] + f[S][j]) % kM;
					} else {
						f[S | (1 << (i - 1))][j + 1] = (f[S | (1 << (i - 1))][j + 1] + f[S][j]) % kM;
					}
				}
			}
		}
		int ans = 0;
		for(int i = m; i <= n; i++) ans = (ans + f[(1 << n) - 1][n - i]) % kM;
		cout << ans << '\n';
	}
	return 0;
} 
