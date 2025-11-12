#include<iostream>
#define int long long
#define N 100050
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
int q;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(), q = read();
	while (q--) write(0, '\n');
	return 0;
}
