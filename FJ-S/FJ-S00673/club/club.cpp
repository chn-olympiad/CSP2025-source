#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 100005;
int n, a[4][N];
int lst[4][N], cnt[4];
int A, B, C, Q[N];
int ans;
void run() {
	cin >> n; cnt[1] = cnt[2] = cnt[3] = ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[1][i] >> a[2][i] >> a[3][i];
		int pfr;
		if (a[1][i] >= a[2][i]) pfr = 1; else pfr = 2;
		if (a[pfr][i] < a[3][i]) pfr = 3;
		lst[pfr][++cnt[pfr]] = i, ans += a[pfr][i];
	}
	if (cnt[1] >= cnt[2]) A = 1; else A = 2; if (cnt[A] < cnt[3]) A = 3;
	B = 1 + (A == 1), C = 3 - (A == 3);
	for (int i = 1; i <= cnt[A]; i++) {
		int s = lst[A][i];
		int big; if (a[B][s] >= a[C][s]) big = B; else big = C;
		Q[i] = a[A][s] - a[big][s];
	} sort(Q + 1, Q + cnt[A] + 1);
	for (int i = 1; cnt[A] > n / 2; i++, cnt[A]--) ans -= Q[i];
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--) run();
}
