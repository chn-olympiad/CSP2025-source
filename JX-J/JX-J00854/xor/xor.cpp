#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005], xs[500005];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	ll maxx = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		xs[i] = xs[i - 1] ^ a[i];
		maxx = max(maxx, a[i]);
	}
	if (maxx <= 1) {
		if (k == 0) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) ans++;
				else if (i != n && a[i] == a[i + 1]) {
					ans++;
					i++;
				}
			}
			cout << ans << endl;
			return 0;
		} else if (k == 1) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) ans++;
			}
			cout << ans << endl;
			return 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((xs[j] ^ xs[i - 1]) == k) {
				while (i < j && a[j] == a[i]) {
					i++;
					j--;
				}
				ans++;
				i = j;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
// luogu uid: 1277793
