#include<bits/stdc++.h>
#define int long long
#define N 510 
#define MOD 998244353
using namespace std;
inline int read() {
	int x = 0, f = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) f = c == '-';
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}
inline void write(int x, int ed = -1) {
	if (x < 0) { x = -x; putchar('-'); }
	int i = 0; static char buf[45];
	do { buf[i++] = x % 10; x /= 10; } while (x);
	while (i) putchar(buf[--i] + 48);
	if (~ed) putchar(ed);
}
int n, m, ans, s[N], c[N], fac[N], p[N], t[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read(); fac[0] = 1;
	for (int i = 1; i <= n; ++i) scanf("%1lld", &s[i]), p[i] = i;
	for (int i = 1; i <= n; ++i) c[i] = read(), fac[i] = fac[i - 1] * i % MOD;
	if (m == n) {
		int f = 1;
		for (int i = 1; i <= n; ++i)  
			if (!s[i] || !c[i]) f = 0;
		write(f * fac[n]);
	}
	else if (n <= 10) {
		do {
			int ban = 0;
			for (int i = 1; i <= n; ++i) 
				if (c[p[i]] <= ban || !s[i]) ++ban;
			ans = (ans + (n - ban >= m ? 1 : 0)) % MOD;
		}while (next_permutation(p + 1, p + 1 + n));
		return write(ans), 0;
	}
	else write(0);
	return 0;
}
/*
3 2
101 
1 1 2
 * */
