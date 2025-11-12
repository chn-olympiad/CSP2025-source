#include<bits/stdc++.h>
#define N 5050
#define MOD 998244353
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) f = c == '-';
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}
inline void write(int x, int ed = -1) {
    if (x < 0) { x = -x; putchar('-'); }
    int i = 0; static char buf[40];
    do { buf[i++] = x % 10; x /= 10; } while(x);
    while (i) putchar(buf[--i] + '0');
    if (~ed) putchar(ed);
}
int n, ans, maxn, a[N], dp[N][N << 1], sum[N << 1] { 1 };
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), maxn = max(maxn, a[i]);
	sort(a + 1, a + n + 1); maxn = maxn * 2 + 10;
	for (int i = 1; i <= n; ++i) {
		for (int j = a[i]; j <= maxn; ++j) dp[i][j] = sum[j - a[i]];
		for (int j = maxn - a[i] + 1; j <= maxn; ++j) (dp[i][maxn] += sum[j]) %= MOD;
		for (int j = 0; j <= maxn; ++j) (sum[j] += dp[i][j]) %= MOD;
	}
	for (int i = 3; i <= n; ++i)
		for (int j = 2 * a[i] + 1; j <= maxn; ++j) (ans += dp[i][j]) %= MOD;
	write(ans, '\n');
	return 0;
}
