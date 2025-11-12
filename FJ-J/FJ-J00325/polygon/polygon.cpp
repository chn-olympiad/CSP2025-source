// 蒟蒻不会QwQ,纯暴力还是手动挡的写了一个,按理来说AC3个点
// 12pts
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 998244353
#define N 5005

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 3) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b > c && a + c > b && b + c > a) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	} else {
		for (int i = 1; i <= n; i ++) {
			int t;
			cin >> t;
		}
//		cout << ans / 5 * 3;
		cout << "CSP-J2025 RP++!!!";
	}
	return 0;
}
// CSP-J2025 rp++！
// 估分272pts 
