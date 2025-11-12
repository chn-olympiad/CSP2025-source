#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= int(r); ++i)
#define rep2(i, l, r) for (int i = l; i >= int(r); --i)
#define rer(i, l, r, a) rep1(i, l, r) read(a[i])
#define fst first
#define snd second
#define mp make_pair
#define eb emplace_back
#define il inline
#define ptc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 1e5 + 10, inf = ~0U >> 2, INF = ~0U >> 1;
namespace stupid_lrc {
	template <typename T> il void read(T &x) {
		x = 0; char ch; int f = 1;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}

	template <typename T, typename ...L> il void read(T &x, L &...y) {
		read(x); read(y...);
	}

	template <typename T> il void read(pair <T, T> &x) {
		read(x.fst, x.snd);
	}

	il int read() {
		int x; read(x); return x;
	}

	template <typename T> il void gmin(T &x, T y) {
		x = x < y ? x : y;
	}

	template <typename T> il void gmax(T &x, T y) {
		x = x > y ? x : y;
	}
}
using namespace stupid_lrc;
int n, cnt[3]; pii a[MAXN][3];

il void solve() {
	read(n); cnt[0] = cnt[1] = cnt[2] = 0;
	ll sum = 0;
	rep1(i, 1, n) {
		rep1(j, 0, 2) read(a[i][j].fst), a[i][j].snd = j;
		sort(a[i], a[i] + 3, greater<>());
		sum += a[i][0].fst; ++cnt[a[i][0].snd];
	} int mx = 0;
	rep1(i, 1, 2) if (cnt[i] > cnt[mx]) mx = i;
	if (cnt[mx] > n / 2) {
		vector <int> dt;
		rep1(i, 1, n) if (a[i][0].snd == mx) dt.eb(a[i][0].fst - a[i][1].fst);
		sort(begin(dt), end(dt));
		int p = cnt[mx] - n / 2;
		rep1(i, 0, p - 1) sum -= dt[i];
	} printf("%lld\n", sum);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (int T = read(); T--; solve());
	return 0;
}

