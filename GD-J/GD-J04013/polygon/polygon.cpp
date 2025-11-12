#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
int a[maxn];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	} 
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int sum = a[i] + a[j], maxa = max(a[i], a[j]), m = 2;
			for (int k = j + 1; k <= n; ++k) {
				if (sum + a[k] > 2 * max(maxa, a[k])) {
					sum += a[k];
					maxa = max(maxa, a[k]);
					ans += m;
					++m;
				}
			}
		}
	}
	cout << ans;
}
