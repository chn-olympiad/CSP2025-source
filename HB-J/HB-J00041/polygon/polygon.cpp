#include <bits/stdc++.h>
#define fori(na, st, ed) for (int na = st; na <= ed; ++na)
#define forn(na, ed) fori(na, 1, ed)
#define fora(na, st, ed) for (int na = st; na >= ed; --na)
#define fors(na, st) fora(na, st, 1)
#ifdef __linux__
#define ffgetc getchar_unlocked
#define ffputc putchar_unlocked
#else
#define ffgetc getchar
#define ffputc putchar
#endif
using namespace std;
template <typename Tp> void read(Tp &x) {
	x = 0;
	char ch = 0;
	int f = 1;
	while (ch < '0' || ch > '9') {
		ch = ffgetc();
		if (ch == '-') {
			f = -1;
		}
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch ^ 48);
		ch = ffgetc();
	}
	x *= f;
}
template <typename T1, typename... T2> void read(T1 &x, T2 &...y) {
	read(x);
	read(y...);
}
const int N = 1e5 + 5, MOD = 998244353;
int n, a[N], ans;
void dfs(int x, int sum, int maxx, int cnt) {
	if (x == n + 1) {
		if (cnt >= 3 && sum > 2 * maxx) {
			ans++;
			if (ans > MOD) {
				ans -= MOD;
			}
		}
		return;
	}
	dfs(x + 1, sum + a[x], max(maxx, a[x]), cnt + 1);
	dfs(x + 1, sum, maxx, cnt);
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	read(n);
	forn(i, n) { read(a[i]); }
	dfs(1, 0, 0, 0);
	printf("%d", ans);
	return 0;
}
// feropen("polygen.in", "w", stdout);
// feropen("polygen.ans", "r", stdin);
// #Shang4Shan3Ruo6Shui4
