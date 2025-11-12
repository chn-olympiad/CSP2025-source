#include <bits/stdc++.h>
using namespace std;
struct Node {
	int a, b, c;
}arr[100005];
int t[100005], cnt;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].a >> arr[i].b >> arr[i].c;
			int mx = max ({arr[i].a, arr[i].b, arr[i].c});
			if (mx == arr[i].a) {
				cnt1++;
			} else {
				if (mx == arr[i].b) {
					cnt2++;
				} else {
					cnt3++;
				}
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			int mx = max ({arr[i].a, arr[i].b , arr[i].c});
			ans += mx;
		}
		if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
			cout << ans << '\n';
			continue;
		}
		if (cnt1 > n / 2) {
			for (int i = 1; i <= n; i++) {
				int mx = max ({arr[i].a, arr[i].b , arr[i].c});
				if (mx == arr[i].a) {
					t[++cnt] = arr[i].a - max (arr[i].b, arr[i].c);
				}
			}
		}
		if (cnt2 > n / 2) {
			for (int i = 1; i <= n; i++) {
				int mx = max ({arr[i].a, arr[i].b , arr[i].c});
				if (mx == arr[i].b) {
					t[++cnt] = arr[i].b - max (arr[i].a, arr[i].c);
				}
			}
		}
		if (cnt3 > n / 2) {
			for (int i = 1; i <= n; i++) {
				int mx = max ({arr[i].a, arr[i].b , arr[i].c});
				if (mx == arr[i].c) {
					t[++cnt] = arr[i].c - max (arr[i].a, arr[i].b);
				}
			}
		}
		sort (t + 1, t + 1 + cnt);
		for (int i = 1; i <= max ({cnt1, cnt2, cnt3}) - n / 2; i++) {
			ans -= t[i];
		}
		cout << ans << '\n';
		memset (t, 0, sizeof(t));
		cnt = 0;
	}
	return 0;
}
