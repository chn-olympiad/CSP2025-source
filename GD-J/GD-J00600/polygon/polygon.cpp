#include <bits/stdc++.h>
using namespace std;

const int N = 5005, mod = 998244353;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	if (n == 3) {
		if (a[1] + a[2] > a[3]) ans++;
		cout << ans << endl;
	} else if (n == 4) {
		if (a[1] + a[2] > a[3]) ans++;
		if (a[1] + a[2] > a[4]) ans++;
		if (a[2] + a[3] > a[4]) ans++;
		if (a[1] + a[2] + a[3] > a[4]) ans++;
		cout << ans << endl;
	} else if (n == 5) {
		if (a[1] + a[2] > a[3]) ans++;
		if (a[1] + a[2] > a[4]) ans++;
		if (a[1] + a[2] > a[5]) ans++;
		if (a[1] + a[3] > a[4]) ans++;
		if (a[1] + a[3] > a[5]) ans++;
		if (a[1] + a[4] > a[5]) ans++;
		if (a[2] + a[3] > a[4]) ans++;
		if (a[2] + a[3] > a[5]) ans++;
		if (a[2] + a[4] > a[5]) ans++;
		if (a[3] + a[4] > a[5]) ans++;
		if (a[1] + a[2] + a[3] > a[4]) ans++;
		if (a[1] + a[2] + a[3] > a[5]) ans++;
		if (a[1] + a[2] + a[4] > a[5]) ans++;
		if (a[1] + a[3] + a[4] > a[5]) ans++;
		if (a[2] + a[3] + a[4] > a[5]) ans++;
		if (a[1] + a[2] + a[3] + a[4] > a[5]) ans++;
		cout << ans << endl;
	} else if (n == 6) {
		if (a[1] + a[2] > a[3]) ans++;
		if (a[1] + a[2] > a[4]) ans++;
		if (a[1] + a[2] > a[5]) ans++;
		if (a[1] + a[2] > a[6]) ans++;
		if (a[1] + a[3] > a[4]) ans++;
		if (a[1] + a[3] > a[5]) ans++;
		if (a[1] + a[3] > a[6]) ans++;
		if (a[1] + a[4] > a[5]) ans++;
		if (a[1] + a[4] > a[6]) ans++;
		if (a[1] + a[5] > a[6]) ans++;
		if (a[2] + a[3] > a[4]) ans++;
		if (a[2] + a[3] > a[5]) ans++;
		if (a[2] + a[3] > a[6]) ans++;
		if (a[2] + a[4] > a[5]) ans++;
		if (a[2] + a[4] > a[6]) ans++;
		if (a[2] + a[5] > a[6]) ans++;
		if (a[3] + a[4] > a[5]) ans++;
		if (a[3] + a[4] > a[6]) ans++;
		if (a[3] + a[5] > a[6]) ans++;
		if (a[4] + a[5] > a[6]) ans++;
		if (a[1] + a[2] + a[3] > a[4]) ans++;
		if (a[1] + a[2] + a[3] > a[5]) ans++;
		if (a[1] + a[2] + a[3] > a[6]) ans++;
		if (a[1] + a[2] + a[4] > a[5]) ans++;
		if (a[1] + a[2] + a[4] > a[6]) ans++;
		if (a[1] + a[2] + a[5] > a[6]) ans++;
		if (a[1] + a[3] + a[4] > a[5]) ans++;
		if (a[1] + a[3] + a[4] > a[6]) ans++;
		if (a[1] + a[3] + a[5] > a[6]) ans++;
		if (a[1] + a[4] + a[5] > a[6]) ans++;
		if (a[2] + a[3] + a[4] > a[5]) ans++;
		if (a[2] + a[3] + a[4] > a[6]) ans++;
		if (a[2] + a[3] + a[5] > a[6]) ans++;
		if (a[2] + a[4] + a[5] > a[6]) ans++;
		if (a[3] + a[4] + a[5] > a[6]) ans++;
		if (a[1] + a[2] + a[3] + a[4] > a[5]) ans++;
		if (a[1] + a[2] + a[3] + a[4] > a[6]) ans++;
		if (a[1] + a[2] + a[3] + a[5] > a[6]) ans++;
		if (a[1] + a[2] + a[4] + a[5] > a[6]) ans++;
		if (a[1] + a[3] + a[4] + a[5] > a[6]) ans++;
		if (a[2] + a[3] + a[4] + a[5] > a[6]) ans++;
		if (a[1] + a[2] + a[3] + a[4] + a[5] > a[6]) ans++;
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
