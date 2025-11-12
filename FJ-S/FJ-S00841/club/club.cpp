#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int t, n, a[N][3], b[N][3], c[3], d[N], ans;
void solve() {
	cin >> n; c[0] = c[1] = c[2] = ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) cin >> a[i][j];
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) b[++ c[0]][0] = i;
		else if(a[i][1] >= a[i][2]) b[++ c[1]][1] = i;
		else b[++ c[2]][2] = i;
		ans += max(max(a[i][0], a[i][1]), a[i][2]);
	}
	if(c[0] > n / 2) {
		for (int i = 1; i <= c[0]; i++) d[i] = a[b[i][0]][0] - max(a[b[i][0]][1], a[b[i][0]][2]);
		sort(d + 1, d + c[0] + 1);
		for (int i = 1; i <= c[0] - n / 2; i++) ans -= d[i];
	}
	if(c[1] > n / 2) {
		for (int i = 1; i <= c[1]; i++) d[i] = a[b[i][1]][1] - max(a[b[i][1]][0], a[b[i][1]][2]);
		sort(d + 1, d + c[1] + 1);
		for (int i = 1; i <= c[1] - n / 2; i++) ans -= d[i];
	}
	if(c[2] > n / 2) {
		for (int i = 1; i <= c[2]; i++) d[i] = a[b[i][2]][2] - max(a[b[i][2]][0], a[b[i][2]][1]);
		sort(d + 1, d + c[2] + 1);
		for (int i = 1; i <= c[2] - n / 2; i++) ans -= d[i];
	} cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t --) solve();
	return 0;
}
