#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int t, n;
struct node {
	int A, B, C;
} a[N];
int dp[205][205][205];
void Little () {
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int A = 0; A <= i; A++) {
			for (int B = 0; B <= i - A; B++) {
				int C = i - A - B; 
				if (C > n / 2 || A > n / 2 || B > n / 2) continue;
				if (A != 0) dp[A][B][C] = max(dp[A - 1][B][C] + a[i].A, dp[A][B][C]);
				if (B != 0) dp[A][B][C] = max(dp[A][B - 1][C] + a[i].B, dp[A][B][C]);
				if (C != 0) dp[A][B][C] = max(dp[A][B][C - 1] + a[i].C, dp[A][B][C]);
//				cout << dp[A][B][C] << " ";
			}
		}
	}
	int ans = 0;
	for (int A = 0; A <= n; A++) {
		for (int B = 0; B <= n - A; B++) {
			int C = n - A - B;
			if (C > n / 2 || A > n / 2 || B > n / 2) continue;
			ans = max(ans, dp[A][B][C]);
//			cout << A << " " << B << " " << C << " " << dp[A][B][C] << "\n";
		}
	}
	cout << ans << "\n";
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].A >> a[i].B >> a[i].C;
	}
	if (n <= 200) {
		Little();
		return;
	} else {
		int A = 0, B = 0, C = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].A >= a[i].B && a[i].A >= a[i].C) A++;
			if (a[i].B >= a[i].A && a[i].B >= a[i].C) B++;
			if (a[i].C >= a[i].B && a[i].C >= a[i].A) C++;
			ans += max({a[i].A, a[i].B, a[i].C});
		} 
		int bian[N] = {}, tot = 0, cha;
		if (A > n / 2) {
			cha = A - n / 2;
			for (int i = 1; i <= n; i++) {
				if (a[i].A >= a[i].B && a[i].A >= a[i].C) {
					bian[++tot] = a[i].A - max(a[i].B, a[i].C);
				}
			}
		} else if (B > n / 2) {
			cha = B - n / 2;
			for (int i = 1; i <= n; i++) {
				if (a[i].B >= a[i].A && a[i].B >= a[i].C) {
					bian[++tot] = a[i].B - max(a[i].A, a[i].C);
				}
			}
		} else if (C > n / 2) {
			cha = C - n / 2;
			for (int i = 1; i <= n; i++) {
				if (a[i].C >= a[i].B && a[i].C >= a[i].A) {
					bian[++tot] = a[i].C - max(a[i].A, a[i].B);
				}
			}
		} else {
			cout << ans << "\n"; return;
		}
		sort(bian + 1, bian + tot + 1);
		for (int i = 1; i <= cha; i++) ans -= bian[i];
		cout << ans << "\n"; return; 
	}
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t; while(t--) solve();
	return 0;
}
// We will win in CSP-S2025!
// We will have 210 pts!
// OK we have 100 pts now in 15:18.
