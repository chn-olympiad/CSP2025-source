#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define fs first
#define sc second
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
#define lc ls, l, mid
#define rc rs, mid + 1, r
#define gc getchar
#define pc putchar

using namespace std;
using pii = pair<int, int>;

const int maxn = 1e3 + 10;
const int mod = 998244353;
const bool multidata = 0;

template<typename T = int>
T read() {
	int x = 0, f = 1;
	char c = gc();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = gc();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = gc();
	}
	return x * f;
}

template<typename T = int>
void write(T x) {
	if (x < 0) pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	pc(x % 10 + '0');
}

int n, m;
int s[maxn], lb[maxn];
int c[maxn];
int tmp[1 << 18][19]; 
int f[maxn][maxn];
int C[maxn][maxn];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void fake_main() {
	n = read(), m = read();
	string qwq; cin >> qwq;
	lb[0] = 1;
	rep(i, 0, n - 1) s[i + 1] = qwq[i] - '0', lb[i + 1] = lb[i] + (!s[i + 1]);
	rep(i, 1, n) c[i] = read();
	if (n <= 18) {
		tmp[0][0] = 1;
		rep(S, 0, (1 << n) - 1) {
			int p = __builtin_popcount(S);
			rep(j, 1, n) if (!(S >> j - 1 & 1)) {
				rep(i, 0, p) add(tmp[S ^ (1 << j - 1)][i + !(s[p + 1] & (i < c[j]))], tmp[S][i]);
			}
		}
		int ans = 0;
		rep(i, 0, n - m) add(ans, tmp[(1 << n) - 1][i]);
		write(ans);
		return;
	}
	if (m == n) {
		rep(i, 1, n) if (s[i] == 0) return void (puts("0"));
		rep(i, 1, n) if (c[i] == 0) return void (puts("0"));
		int ans = 1;
		rep(i, 1, n) ans = ans * i % mod;
		write(ans);
		return;
	}
	if (m == 1) {
		sort(c + 1, c + 1 + n);
		int ans = 1, qwq = 1, cnt = 0;
		rep(i, 1, n) ans = ans * i % mod;
		rep(i, 1, n) if (s[i] == 1) {
			int p = upper_bound(c + 1, c + 1 + n, i - 1) - c - 1;
			qwq = qwq * max(p - cnt, 0ll) % mod;
			++cnt;
		}
		rep(i, 1, n - cnt) qwq = qwq * i % mod;
		write((ans - qwq + mod) % mod);
		return;
	}
	C[0][0] = 1;
	rep(i, 1, n) {
		C[i][0] = C[i][i] = 1;
		rep(j, 1, i - 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	sort(c + 1, c + 1 + n);
	int ans = 0;
	rep(K, m, n) {
//		rep(i, 0, n + 1) rep(j, 0, min(n - i + 1, K)) f[i][j] = 0; 
		memset(f, 0, sizeof(f));
		f[n + 1][0] = 1;
		per(i, n, 1) {
			rep(k, 0, K) {
				int p = lower_bound(c + 1, c + 1 + n, i - K + k) - c;
				add(f[i][k], f[i + 1][k]);
				if (k && s[i]) add(f[i][k], f[i + 1][k - 1] * max(n - p + 1 - k + 1, 0ll) % mod);
			}
		}
		int now = f[1][K];
		rep(j, 1, n - K) now = now * j % mod;
		int x = 0;
		rep(i, m, K) (x += (((K - i) & 1) ? mod - 1 : 1) * C[K][i] % mod) %= mod;
		add(ans, now * x % mod);
	}
	write(ans);
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = multidata ? read() : 1;
	while (T--) fake_main();
	return 0;
}
/*
不是，我熔池为啥不对？？？
10 1
1101111011
6 0 4 2 1 2 5 4 3 3
*/
