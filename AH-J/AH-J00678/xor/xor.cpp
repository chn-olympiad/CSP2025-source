#include<iostream>
#include<cstring>
#define int long long
#define N 500500
#define W (1 << 21)
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
int n, k, a[N], dp[N], lst[W];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read(); memset(lst, -1, sizeof lst); lst[0] = 0;
	for (int i = 1; i <= n; ++i) a[i] = read() ^ a[i - 1];
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(dp[i - 1], ~lst[a[i] ^ k] ? dp[lst[a[i] ^ k]] + 1 : -1);
		lst[a[i]] = i; 
	}
	write(dp[n], '\n');
	return 0;
}
