#include<bits/stdc++.h>
using namespace std;
int n, a[5005];
int main() {
	cin >> n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 2) {
		cout << 0;
		return 0;
	} else {
		int s = a[1] + a[2] + a[3];
		int mx = max(a[1], max(a[2], a[3]));
		if (s > 2 * mx) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}