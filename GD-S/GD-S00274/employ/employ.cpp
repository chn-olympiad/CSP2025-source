#include <bits/stdc++.h>
using namespace std;

#define FIONAME "employ"
constexpr int MOD = 998244353;
int gcv (void) {
	int ch;
	while (1) {
		ch = getchar ();
		if (isdigit (ch) || isalpha (ch)) return ch;
	}
}
int s[512];
int c[512];
int solca (int n) {
	int cnt0 = 0;
	for (int i = 1; i <= n; ++i) {
		cnt0 += (c[i] == 0);
	}
	long long ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = ans * i % MOD;
	}
	printf ("%lld", ans);
	return 0;
}
int sol18 (int n, int m) {
	int p[32] = {0};
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
	}
	int ans = 0;
	do {
		int fcnt = 0, tot = 0;
		for (int i = 1; i <= n; ++i) {
			if (fcnt >= c[p[i]] || s[i] == 0) {
				++ fcnt;
			} else {
				++ tot;
			}
		}
		(ans += (tot >= m)) %= MOD;
	} while (next_permutation (p + 1, p + 1 + n));
	printf ("%d", ans);
	return 0;
}
int f[1 << 18][24];
int sol345 (int n, int m) {
	int N = 1 << n;
	f[0][0] = 1;
	for (int S = 0; S + 1 < N; ++S) {
		auto popcnt = [] (const int x) {
			return (x == 0) ? (0) : (__builtin_popcount (x));
		};
		int tot = popcnt (S), id = tot + 1;
		for (int suc = 0, fcnt = tot; suc <= tot; ++ suc, --fcnt) {
			for (int i = 1; i <= n; ++i) {
				int bmask = 1 << (i - 1);
				if (S & bmask) continue;
				if (fcnt >= c[i] || s[id] == 0) {
					int & obj = f[S | bmask][suc];
					(obj += f[S][suc]) %= MOD;
				} else {
					int & obj = f[S | bmask][suc + 1];
					(obj += f[S][suc]) %= MOD;
				}
			}
		}
	}
	int ans = 0;
	for (int j = m; j <= n; ++j) {
		(ans += f[N - 1][j]) %= MOD;
	}
	printf ("%d", ans);
	return 0;
}
int main (void) {
	freopen (FIONAME ".in", "r", stdin);
	freopen (FIONAME ".out", "w", stdout);
	int n, m;
	scanf ("%d%d", &n, &m);
	int cntca = 0;
	for (int i = 1; i <= n; ++i) {
		s[i] = gcv () - '0';
		cntca += s[i];
	}
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", c + i);
	}
	if (cntca == n) {
		return solca (n);
	}
	if (n <= 10) {
		return sol18 (n, m);
	}
	if (n <= 18) {
		//	modify
		return sol345 (n, m);
	}
	return 0;
}
