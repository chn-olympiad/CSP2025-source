#include <bits/stdc++.h>
using namespace std;

#define LOCAL
//#define DEBUG

typedef long long int ll;
typedef pair<int, int> PII;

const int N = 1e3 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, cnt, ans;
int a[N];
int l1[N], r1[N], l2[N], r2[N];

#if defined(__unix__) || defined(__linux__)
#define getchar getchar_unlocked
#else
#define getchar _getchar_nolock
#endif

namespace IO_fast_int32 {
	inline void read(int& x) {
		x = 0;
		int f = 1;
		char ch = getchar();

		while (!isdigit(ch)) {
			if (ch == '-') f = -1;
			ch = getchar();
		}

		while (isdigit(ch)) {
			x = (x << 3) + (x << 1) + (ch ^ 48);
			ch = getchar();
		}

		x = x * f;
	}

	inline void write(int x) {
		if (x < 0) {
			putchar('-');
			x = -x;
		}

		if (x > 9) write(x / 10);
		putchar((char)(x % 10 + 48));
	}

	inline void writefln(int x) {
		write(x);
		putchar(' ');
	}

	inline void writeln(int x) {
		write(x);
		putchar('\n');
	}

	template <typename ..._Tp>
	inline void read(int& x, _Tp& ...y) {
		read(x);
		read(y...);
	}

	template <typename ..._Tp>
	inline void writefln(int x, _Tp ...y) {
		writefln(x);
		writefln(y...);
	}

	template <typename ..._Tp>
	inline void writeln(int x, _Tp ...y) {
		writeln(x);
		writeln(y...);
	}
}

using namespace IO_fast_int32;

string s1, s2;

inline void solve() {
	cin >> n >> m;
	while (m --) cout << 0 << "\n";
}

int main(int argc, const char *argv[]) {
#ifdef LOCAL
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#else
	freopen("replace4.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
//	cin >> t;

	while (t --) {
		solve();
	}

	return 0;
}

