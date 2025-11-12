#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define ll long long
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

template <typename T> inline void rd(T& x) {
	x = 0; int f = 1;
	char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = getchar();
	x *= f;
}

template <typename T> inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	static short s[20], _ = 0;
	do s[++_] = x%10, x /= 10; while (x);
	while (_) putchar(s[_--]|48);
}

template <typename T, typename ...Args> inline void rd(T &x, Args&... _) { rd(x); rd(_...); }

const int N = 1e5+5;
int n, ans, a[N][4], b[4], p[N];

void solve() {
	ans = 0; memset(b, 0, sizeof(b));
	rd(n); ans = 0;
	for (int i = 1; i <= n; ++i) {
		int pos = 0;
		for (int j = 1; j <= 3; ++j) {
			rd(a[i][j]);
			if (a[i][j] >= a[i][pos]) pos = j;
		}
		p[i] = pos; ++b[pos]; ans += a[i][pos];
	}
	int pos = 0;
	for (int i = 1; i <= 3; ++i) if (b[i] > n/2) pos = i;
	if (pos) {
		vi v;
		for (int i = 1; i <= n; ++i) if (p[i] == pos) {
			sort(a[i]+1, a[i]+4);
			v.pb(a[i][3]-a[i][2]);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < b[pos]-n/2; ++i) ans -= v[i];
	}
	write(ans), enter;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; rd(t);
	while (t--) solve();
	return 0;
}
