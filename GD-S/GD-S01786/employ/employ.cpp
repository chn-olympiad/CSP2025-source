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
	void read(string &s) {
		char ch; s = "";
		do ch = gc(); while (ch <= 32 || ch >= 127);
		do s += ch, ch = gc(); while (ch > 32 && ch < 127);
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

const int mod = 998244353;
inline int fplus(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int Fplus(int &x, int y) { return x = fplus(x, y); }
inline int fminus(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline int Fminus(int &x, int y) { return x = fminus(x, y); }
int n, m, a[20], f[1<<18][20];

bool Med;

int main() {
	assert(freopen("employ.in", "r", stdin));
	assert(freopen("employ.out", "w", stdout));
	fprintf(stderr, "%f\n", (&Mst - &Med) / 1048576.0);	
	read(n, m);
	string s; read(s);
	for (int i = 0; i < n; ++i) read(a[i]);
	f[0][0] = 1;
	for (int S = 0; S < (1 << n) - 1; ++S) {
		int t = __builtin_popcount(S);
		for (int x = 0; x < n; ++x) {
			if (S >> x & 1) continue;
			for (int v = 0; v <= n; ++v)
				Fplus(f[S | 1 << x][v + (s[t] == '0' || a[x] <= v)], f[S][v]);
		}
	}
	int sum = 0;
	for (int v = 0; v <= n - m; ++v) Fplus(sum, f[(1 << n) - 1][v]);
	write(sum);
	return 0;
}
