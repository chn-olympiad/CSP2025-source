#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, b1, b2, b3, sum = 0, max1 = 0, max2 = 0, max3 = 0;
		cin >> n;
		int a[n + 5], b[n + 5], c[n + 5];
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			max1 = max(max1, a[i]);
			max2 = max(max2, b[i]);
			max3 = max(max3, c[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (max(c[i], max(a[i], b[i])) == a[i]) b1++, sum += a[i];
			else if (max(c[i], max(a[i], b[i])) == b[i]) b2++, sum += b[i];
			else if (max(c[i], max(a[i], b[i])) == c[i]) b3++, sum += c[i];
		}
		if (b1 <= n / 2 && b2 <= n / 2 && b3 <= n / 2) cout << sum << endl;
		else {
			for (int i = 1; i <= n; i++) {
				if (b1 > n / 2 && b2 + 1 <= n / 2 && a[i] < max1) sum -= a[i], sum += b[i], b1--, b2++;
				else if (b1 > n / 2 && b3 + 1 <= n / 2 && a[i] < max1) sum -= a[i], sum += c[i], b1--, b3++;
				if (b2 > n / 2 && b1 + 1 <= n / 2 && b[i] < max2) sum -= b[i], sum += a[i], b2--, b1++;
				else if (b2 > n / 2 && b3 + 1 <= n / 2 && b[i] < max2) sum -= b[i], sum += c[i], b2--, b3++;
				if (b3 > n / 2 && b1 + 1 <= n / 2 && c[i] < max3) sum -= c[i], sum += a[i], b3--, b1++;
				else if (b3 > n / 2 && b2 + 1 <= n / 2 && c[i] < max3) sum -= c[i], sum += b[i], b3--, b2++;				
			}
			for (int i = 1; i <= n; i++) {
				if (b2 > n / 2 && b1 + 1 <= n / 2 && b[i] < max2) sum -= b[i], sum += a[i], b2--, b1++;
				else if (b2 > n / 2 && b3 + 1 <= n / 2 && b[i] < max2) sum -= b[i], sum += c[i], b2--, b3++;
				if (b3 > n / 2 && b1 + 1 <= n / 2 && c[i] < max3) sum -= c[i], sum += a[i], b3--, b1++;
				else if (b3 > n / 2 && b2 + 1 <= n / 2 && c[i] < max3) sum -= c[i], sum += b[i], b3--, b2++;
				if (b1 > n / 2 && b2 + 1 <= n / 2 && a[i] < max1) sum -= a[i], sum += b[i], b1--, b2++;
				else if (b1 > n / 2 && b3 + 1 <= n / 2 && a[i] < max1) sum -= a[i], sum += c[i], b1--, b3++;				
			}
			for (int i = 1; i <= n; i++) {
				if (b3 > n / 2 && b1 + 1 <= n / 2 && c[i] < max3) sum -= c[i], sum += a[i], b3--, b1++;
				else if (b3 > n / 2 && b2 + 1 <= n / 2 && c[i] < max3) sum -= c[i], sum += b[i], b3--, b2++;
				if (b1 > n / 2 && b2 + 1 <= n / 2 && a[i] < max1) sum -= a[i], sum += b[i], b1--, b2++;
				else if (b1 > n / 2 && b3 + 1 <= n / 2 && a[i] < max1) sum -= a[i], sum += c[i], b1--, b3++;
				if (b2 > n / 2 && b1 + 1 <= n / 2 && b[i] < max2) sum -= b[i], sum += a[i], b2--, b1++;
				else if (b2 > n / 2 && b3 + 1 <= n / 2 && b[i] < max2) sum -= b[i], sum += c[i], b2--, b3++;				
			}
			cout << sum << endl;
		}
	}
	return 0;
}
