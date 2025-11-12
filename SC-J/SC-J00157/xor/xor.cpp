#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 5e5 + 5;

int n, k, ans;
int L, R;
int a[N];

int sum(int l, int r) {
	int res = a[l];
	for(int i = l + 1; i <= r; i++) {
		res ^= a[i];
	}
	return res;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	// 输入
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	// 存储
	// 排序
	// 处理
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j++) {
			if (sum(i, j) == k) {
				if ((i <= L && j>= L) ||
				        (L <= i && i <= R)) {
					continue;
				}
				ans++;
				L = i, R = j;
			}
		}
	}
	// 输出
	cout << ans << endl;
	return 0;
}