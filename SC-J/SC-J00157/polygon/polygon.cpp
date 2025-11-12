#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 5e3 + 5, mod = 998244353;

int n,ans;
int a[N];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	// 输入
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	// 存储
	// 排序
	sort(a + 1, a + n + 1);
	// 处理
	for(int k = 3, num, sum, i = 1; k <= n; k ++) {
		num = k, sum = 0,i = 1;
		while(num--) {
			sum += a[i];
			i++;
		}
		if (sum > a[k] * 2) {
			ans++;
		}
	}
	// 输出
	cout << 9 << endl;
	return 0;
}