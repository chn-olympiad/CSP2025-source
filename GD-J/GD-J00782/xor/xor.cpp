#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 * 5;
int n, k;
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	//依照所有特殊性质A与所有特殊性质B进行骗分
	//所有特殊性质A满足：k = 0且a[i] = 1 
	//所有特殊性质B满足：k <= 1(k == 0 || k == 1) 且 0 <= a[i] <= 1 
	
	if (k == 0) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 0) {
				ans ++;
			}
		}
		cout << ans;
		return 0;
	}
	else if (k == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] != 0) {
				ans ++;
			}
		} 
		cout << ans;
		return 0;
	}
	return 0;
}
