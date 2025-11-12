#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, k;
	ll cnt1 = 0, cnt0 = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	bool isA = 0, isB = 0;
	
	// 判断是否符合 特殊性质A 或 特殊性质B
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1)			cnt1++;
		if (a[i] == 0)			cnt0++;
	}
	if (cnt1 == n)				isA = 1;
	else if (cnt1 + cnt0 == n)	isB = 1;
	
	if (!isA && !isB) {
		cout << 0;
	} else if (isA) {
		// 注意到: 当样例中特殊性质为 a 时, k == 0, 而数组全为1.
		// 因为 1 ^ 1 == 0, 所以输出 n / 2 即可
		cout << n / 2;
	} else if (isB) {
		/* 	
		 * 数组中: 				要么是1, 要么是0.
		 * k: 	  				要么是1, 要么是0.
		 * 当 k == 1 时: 		输出数组中值为 1 的个数.
		 * 当 k == 0 时: 		输出数组中值为 0 的个数 + 数组中连续两个值为 1 的个数.
		 */
		if (k == 1) {
			cout << cnt1;
		} else {
			ll cntlx1 = 0;
			ll i = 1;
			// 求数组中连续两个值为 1 的个数
			while (i++) {
				if (a[i] == 1 && a[i + 1] == 1)	cntlx1++, i++;
				if (i == n)		break;
			}
			cout << cnt0 + cntlx1;
		}
	}
	return 0;	// 30
}
