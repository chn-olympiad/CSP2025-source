#include <bits/stdc++.h>
#define p 998244353
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

inline bool getb (void) {
	char c = getchar();
	while (c != '1' && c != '0') c = getchar();
	return c == '1';
}

long long n, m, c[1000], f[20][1 << 18], ans;
bool s[1000];

int main(void) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) s[i] = getb();
	for (int i = 0; i < n; i++) c[i] = read();
	f[0][0] = 1;
	for (int i = 0; i < 1 << n; i++) {
		long long cnt = 0;
		for (int j = 0; j < n; j++) if (i >> j & 1) cnt++;
		for (int k = 0; k <= cnt; k++) {
			for (int j = 0; j < n; j++) {
				if (i >> j & 1) continue;
				(f[k + (s[cnt + 1] && c[j] > cnt - k)][i + (1 << j)] += f[k][i]) %= p;
			}
		}
	}
	for (int i = m; i <= n; i++) (ans += f[i][(1 << n) - 1]) %= p;
	printf("%lld", ans);
	return 0;
}
