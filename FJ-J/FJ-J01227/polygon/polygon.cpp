#include <bits/stdc++.h>
#define el "\n"
#define sp " "
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)
#define p 998244353

using namespace std;

typedef long long ll;
typedef string str;

int n;
int a[5100];
bool f[5100];
int ans = 0;
int c[5100][5100];

inline void dfs(int x) {
	if (x == n + 1) {
		int s = 0, ma = INT_MIN;
		F(i, 1, n, 1) {
			s += a[i] * f[i];
			if (f[i]) {
				ma = std::max(ma, a[i]);
			}
		}
		if (accumulate(f + 1, f + n + 1, 0LL) >= 3 && s > ma * 2) {
			ans++;
			if (ans > p) {
				ans -= p;
			}
		}
		return;
	}
	f[x] = 0;
	dfs(x + 1);
	f[x] = 1;
	dfs(x + 1);
}

signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	F(i, 1, n, 1) {
		cin >> a[i];
	}
	if (n <= 20) {
		dfs(1);
		cout << ans << el;
		r0;
	}
	F(i, 0, n + 1, 1) {
		c[i][0] = c[i][i] = 1;
	}
	F(i, 1, n + 1, 1) {
		F(j, 1, i, 1) {
			if (!c[i][j]) {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}
	}
	F(i, 3, n, 1) {
		ans += c[n][i];
	}
	cout << ans << el;
	r0;
}
