#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
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
int n, ans, a[N][4], d[N][4];
priority_queue<int, vector<int>, greater<int> > q[3];
void solve() {
	n = read(); ans = 0;
	q[0] = q[1] = q[2] = priority_queue<int, vector<int>, greater<int> >();
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) a[i][j] = read();
		d[i][0] = a[i][0] - max(a[i][1], a[i][2]);
		d[i][1] = a[i][1] - max(a[i][0], a[i][2]);
		d[i][2] = a[i][2] - max(a[i][1], a[i][0]);
	}
	for (int i = 1; i <= n; ++i) {
		int mx = 0;
		if (a[i][1] > a[i][mx]) mx = 1;
		if (a[i][2] > a[i][mx]) mx = 2;
		q[mx].push(d[i][mx]); ans += a[i][mx];
	}
	for (int i = 0; i < 3; ++i)
			for ( ; q[i].size() > n / 2; q[i].pop()) ans -= q[i].top();
	write(ans, '\n');
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (int T = read(); T--; solve());
	return 0;
}
