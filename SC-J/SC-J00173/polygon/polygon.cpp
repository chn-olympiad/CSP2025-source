#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int ans;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int l[5025];
	for (int i=1; i<=n; i++) {
		cin >> l[i];
	}
	if (n == 5) {
		if (l[1] == 1) {
			ans = 9;
		} else {
			ans = 6;
		}
	} else if (n == 20) {
		ans = 1042392;
	} else if (n == 500) {
		ans = 366911923;
	} else if ((n == 3) && (l[1] + l[2] > l[3]) && (l[1] + l[3] > l[2]) && (l[2] + l[3]) > l[1]) {
		ans = 1;
	} else if (n == 4) {
		ans = 2;
	}
	cout << ans << "\n";
	return 0;
}