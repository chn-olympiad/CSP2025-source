#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int n, k, a[N], x, ans, prefix[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		x ^= a[i];
		if (x == k) {
			ans ++;
			x = 0;
		}
	}
	cout << ans;
	return 0;
}
////	int x = 0;
////	x ^= 2;
////	x ^= 3;
//	for (int i = 1; i <= 7; i ++) {
//		for (int j = i; j <= 7; j ++) {
//			int x = 0;
//			for (int k = i; k <= j; k ++) {
//				x ^= k;
//			}
//			cout << "xor: " << i << " to " << j << " = " << x << endl;
//		}
//	}
////	cout << x;

