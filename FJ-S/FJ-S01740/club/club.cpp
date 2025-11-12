#include <bits/stdc++.h>
using namespace std;
int n, t, mid, sum, ans, flag, flags, k, ta, tb, tc, sa, sb, sc;
struct d {
	int to, ids;
};
d aa[100005], bb[100005], cc[100005];
struct e {
	int f, s, th, id;
}m[100005];
e g[100005];
bool cmp1 (e x, e y) {return x.f > y.f;}
bool cmp2 (e x, e y) {return x.s > y.s;}
bool cmp3 (d x, d y) {return g[x.ids].s > g[y.ids].s;}
bool cmp5 (d x, d y) {return g[x.ids].th > g[y.ids].th;}
void dfs (int x, int a, int b, int c) {
	if (x > n || (2 * a) > n || (2 * b) > n || (2 * c) > n) return;
	if (x == n) ans = max(ans, sum);
	sum += m[x + 1].f;
	dfs (x + 1, a + 1, b, c);
	sum -= m[x + 1].f;
	sum += m[x + 1].s;
	dfs (x + 1, a, b + 1, c);
	sum -= m[x + 1].s;
	sum += m[x + 1].th;
	dfs (x + 1, a, b, c + 1);
	sum -= m[x + 1].th;
}
int main () {
//	freopen ("club3.in", "r", stdin);
//	freopen ("club1.out", "w", stdout);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin.tie (0), cout.tie (0);
	scanf ("%d", &t);
	for (int h = 1; h <= t; h++) {
		scanf ("%d", &n);
		ans = sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d%d%d", &m[i].f, &m[i].s, &m[i].th);
			g[i].id = m[i].id = i;
			if (m[i].s) flag = 1;
			if (m[i].th) flags = 1;
			g[i].s = m[i].s - m[i].f;
			g[i].th = m[i].th - m[i].f;
		}
		if (!flag && !flags) {
			sort (m + 1, m + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++) ans += m[i].f;
			cout << ans << endl;
			continue;
		}
		if (!flags) {
			sort (g + 1, g + n + 1, cmp2);
			for (int i = 1; i <= n; i++) {
				if (i <= n / 2) ans += m[g[i].id].s;
				else ans += m[g[i].id].f;
			}
			cout << ans << endl;
			continue;
		}
		if (n <= 17) {
			dfs (0, 0, 0, 0);
			cout << ans << endl;
			continue;
		}
//		for (int i = 1; i <= n; i++) ans += max (m[i].f, max (m[i].s, m[i].th));
		printf ("%d\n", ans);
	}
	return 0;
} 
