#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n < 3) {
			cout << 0;
			return 0;
	}
	else {
		sort(a + 1, a + n + 1);
		int sum = 0;
		for (int i = 1; i <= n; i++){
			sum += a[i];
		}
		if (sum > a[n] * 2) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
