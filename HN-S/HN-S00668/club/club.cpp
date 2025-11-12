#include <bits/stdc++.h>

#define debug(x) (cout << #x << " " << x << "\n")

using namespace std;

using ll = long long;

const int N = 1e5 + 5;

ll T, n, a[N][4], ans, cnt1, cnt2, cnt3, vis[N], val[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T --) {
		cin >> n;
		ans = cnt1 = cnt2 = cnt3 = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				ans += a[i][1], ++ cnt1;
				vis[i] = 1;
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				ans += a[i][2], ++ cnt2;
				vis[i] = 2;
			} else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
				ans += a[i][3], ++ cnt3;
				vis[i] = 3;
			}
		}
		if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
			cout << ans << "\n";
			continue;
		}
		memset(val, 0xcf, sizeof val);
		if (cnt1 > n / 2) {
			for (ll i = 1; i <= n; i++) if (vis[i] == 1) val[i] = max(a[i][2], a[i][3]) - a[i][1];
			sort(val + 1, val + 1 + n, greater<ll>());
			for (ll i = n / 2; i < cnt1; i++) ans += val[i - n / 2 + 1];
		} else if (cnt2 > n / 2) {
			for (ll i = 1; i <= n; i++) if (vis[i] == 2) val[i] = max(a[i][1], a[i][3]) - a[i][2];
			sort(val + 1, val + 1 + n, greater<ll>());
			for (ll i = n / 2; i < cnt2; i++) ans += val[i - n / 2 + 1];
		} else if (cnt3 > n / 2) {
			for (ll i = 1; i <= n; i++) if (vis[i] == 3) val[i] = max(a[i][1], a[i][2]) - a[i][3];
			sort(val + 1, val + 1 + n, greater<ll>());
			for (ll i = n / 2; i < cnt3; i++) ans += val[i - n / 2 + 1];
		}
		cout << ans << "\n";
	}
	return 0;
}
