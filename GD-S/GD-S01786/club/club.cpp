#include <bits/stdc++.h>
using namespace std;
using LL = long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
namespace FastIO {
	char gc() {
		static char buf[1 << 20], *p1, *p2;
		if (p1 == p2) p1 = buf, p2 = buf + fread(buf, 1, 1 << 20, stdin);
		return p1 == p2 ? EOF : *(p1++);
	}
	template <typename T> void read(T &x) {
		char ch; bool op = 0; x = 0;
		do ch = gc(), op |= ch == '-'; while (ch < '0' || ch > '9');
		do x = x * 10 + (ch & 15), ch = gc(); while (ch >= '0' && ch <= '9');
		if (op) x = -x;
	}
	template <typename T, typename ...U> void read(T &x, U &...y) { read(x), read(y...); }
	template <typename T> void write(T x, char ed = '\n') {
		static int stk[100]; int tp = 0;
		if (x < 0) putchar('-'), x = -x;
		do stk[++tp] = x % 10, x /= 10; while (x);
		for (; tp; --tp) putchar(stk[tp] | 48);
		putchar(ed);
	}
	template <typename T, typename ...U> void write(T x, U ...y) { write(x, ' '), write(y...); }
}
using namespace FastIO;

bool Mst;
int n; 
bool Med;

int main() {
	assert(freopen("club.in", "r", stdin));
	assert(freopen("club.out", "w", stdout));
	// fprintf(stderr, "%f\n", (&Mst - &Med) / 1048576.0);
	int T; read(T);
	while (T--) {
		read(n);
		LL sum = 0;
		vector<vector<int>> v(3);
		for (int i = 1; i <= n; ++i) {
			int a, b, c; read(a, b, c);
			if (a >= b && a >= c) {
				sum += a, v[0].push_back(a - max(b, c));
			} else if (b >= c) {
				sum += b, v[1].push_back(b - max(a, c));
			} else {
				sum += c, v[2].push_back(c - max(a, b));
			}
		}
		for (int o = 0; o < 3; ++o) {
			sort(v[o].begin(), v[o].end());
			int len = v[o].size();
			for (int i = 0; i < len - (n >> 1); ++i) sum -= v[o][i];
		}
		write(sum);
	}
	return 0;
}
