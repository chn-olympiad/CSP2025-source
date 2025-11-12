#include<bits/stdc++.h>
#define int long long
#define N 20
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
int n, m, a[N * N], r;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n * m; ++i) a[i] = read(); r = a[1];
	sort(a + 1, a + n * m + 1, [](int x, int y) { return x > y; });
	for (int i = 1, j = 1, cnt = 1; i <= m && j <= n; ++cnt) {
		if (a[cnt] == r) { write(i, ' '), write(j, '\n'); return 0; }
		if ((j == 1 && i % 2 == 0) or (j == n && i % 2)) ++i;
		else if (i % 2) ++j; else --j;
	}
	return 0;
}
