#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, a[N][4];
struct Node {
	int mx, se;
	int id1, id2;
} b[N];
inline bool cmp(Node x, Node y) {
	return x.mx + y.se > x.se + y.mx;
}
inline void solve() {
	memset(b, 0, sizeof b); 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			if (a[i][j] > b[i].mx) {
				b[i].se = b[i].mx, b[i].id2 = b[i].id1;
				b[i].mx = a[i][j], b[i].id1 = j;
			} else if (a[i][j] > b[i].se) b[i].se = a[i][j], b[i].id2 = j;
 		}
	}	
	sort(b + 1, b + 1 + n, cmp);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i].id1 == 1) {
			if (cnt1 == n / 2) {
				ans += b[i].se;
				if (b[i].se == 2) cnt2++;
				else cnt3++;
			} else cnt1++, ans += b[i].mx;
		} else if (b[i].id1 == 2) {
			if (cnt2 == n / 2) {
				ans += b[i].se;
				if (b[i].se == 1) cnt1++;
				else cnt3++;
			} else cnt2++, ans += b[i].mx;
		} else {
			if (cnt3 == n / 2) {
				ans += b[i].se;
				if (b[i].se == 1) cnt1++;
				else cnt2++;
			} else cnt3++, ans += b[i].mx;
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1; cin >> T; while (T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0 
*/
