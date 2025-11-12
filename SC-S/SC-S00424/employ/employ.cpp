#include <iostream>
#include <algorithm>
#include <vector>
#define Mod 998244353
using namespace std;

void add(int& x, int y) { (x += y) >= Mod and (x -= Mod); }

int n, m, s[501], c[501];

struct Subtask1 {
	int f[262144][19], popc[262144];
	vector<int> v[19];
	void calc() {
		int ans = 0;
		for (int i = 0; i < (1 << n); ++i) {
			popc[i] = popc[i >> 1] + (i & 1);
			v[popc[i]].push_back(i);
		}
		f[0][0] = 1;
		for (int _ = 0; _ < n; ++_) {
			for (int S : v[_]) {
				for (int i = 0; i <= popc[S]; ++i) {
					for (int j = 0; j < n; ++j) {
						if (!(S >> j & 1)) {
							if (popc[S] - i >= c[j + 1] or !s[popc[S] + 1]) {
								add(f[S | (1 << j)][i], f[S][i]);
							} else {
								add(f[S | (1 << j)][i + 1], f[S][i]);
							}
						}
					}
				}
			}
		}
		for (int i = m; i <= n; ++i) {
			add(ans, f[(1 << n) - 1][i]);
		}
		printf("%d\n", ans);
	}
} sub1;

void init() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%1d", s + i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i);
	}
}

void calculate() {
	if (n <= 18) {
		sub1.calc();
	} else if (m == n) {
		int ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans = 1ll * ans * i % Mod;
			if (!s[i] or !c[i]) {
				puts("0");
				return;
			}
		}
		printf("%d\n", ans);
	} else {
		puts("0");
	}
}

void solve() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init(), calculate();
}

int main() {
	solve();
	return 0;
}