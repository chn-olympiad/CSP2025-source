#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N][4], op[N];
int b[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			int now = max(max(a[i][1], a[i][2]), a[i][3]);
			ans += now;
			if (a[i][1] == now) cnt1++, op[i] = 1;
			else if (a[i][2] == now) cnt2++, op[i] = 2;
			else if (a[i][3] == now) cnt3++, op[i] = 3;
		} 
		int cnt = max(max(cnt1, cnt2), cnt3);
		if (cnt <= n / 2) {
			cout << ans << "\n"; continue;
		}
		else {
			int m = 0;
			if (cnt == cnt1) {
				for (int i = 1; i <= n; i++) {
					if (op[i] == 1) b[++m] = a[i][1] - max(a[i][2], a[i][3]);
				}
			}
			if (cnt == cnt2) {
				for (int i = 1; i <= n; i++) {
					if (op[i] == 2) b[++m] = a[i][2] - max(a[i][1], a[i][3]);
				}
			}
			if (cnt == cnt3) {
				for (int i = 1; i <= n; i++) {
					if (op[i] == 3) b[++m] = a[i][3] - max(a[i][1], a[i][2]);
				}
			}
			sort(b + 1, b + m + 1);
			cnt = cnt - (n / 2);
			for (int i = 1; i <= cnt; i++) ans -= b[i];
			cout << ans << "\n";
		}
	}
	return 0; 
}
