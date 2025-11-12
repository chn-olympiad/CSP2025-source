#include <bits/stdc++.h>
using namespace std;
int n, a[5005], sum, maxx = -9999999, num, pre[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i-1] + a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		for (int i = 1; i <= 3; i++) {
			sum += a[i];
			maxx = max(a[i], maxx);
		}
		if (sum > (maxx * 2)) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		
	}
	cout << num;
	return 0;
}
