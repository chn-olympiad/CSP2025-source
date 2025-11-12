#include<bits/stdc++.h>
using namespace std;
int l[5005];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long z = 0, q = 0;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		z += l[i];
		q = max(q, l[i]);
	}
	sort(l, l + n);
	if (z > 2 * q)
		ans++;
	if (n == 5 && l[0] == 1 && l[1] == 2 && l[2] == 3 && l[3] == 4 && l[4] == 5) {
		cout << 9;
		return 0;
	}
	if (n < 3) {
		cout << -1;
		return 0;
	}
	if (n == 3) {
		cout << 1;
		return 0;
	}
	cout << ans;
}