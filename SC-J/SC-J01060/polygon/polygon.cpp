#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Mod 998244353
#define int long long
const int N = 5e3 + 50;
int n, a[N];
bool T = true;
// 40 分 
// 有个性质 ai <= 1 -> 推导公式即可 
int num[N], dp[N], sum[N];
int C(int op, int m) {
	int cnt = op + 1, k = 1, ans = 1;
	while (cnt <= m) {
		num[cnt] = cnt;
		while (num[cnt] % k == 0 && k <= m - op) {
			num[cnt] /= k;
			k++;
		}
		cnt++;
	}
	
	for (int i = op + 1; i <= m; i++) {
		ans *= num[i];
		ans %= Mod;
	}
	
	return ans % Mod;
}
//  总个数 即f(x) 
int Power(int k) {
	int ans = 1;
	while (k > 31) {
		ans <<= 31;
		k -= 31;
		ans %= Mod;
	}
	ans <<= k;
	ans %= Mod;
	return ans - 1;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		if (a[i] > 1) T = false;
	}
	
	if (T == true) {
		int ans = 0;
		for (int i = 3; i <= n; i++) {
			ans += C(i, n);
			ans %= Mod;
		}
		cout << ans;
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	dp[1] = 0, dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		int tmp = a[i] - a[i - 1];
		int r = i - 1;
		while (tmp < a[r] && r >= 1) {
			r--;
		}
		// 第i位有多少选择可以 < a[i]
		dp[i] = dp[i - 1] + dp[r] + 1;
		dp[i] %= Mod;
	}
	
	int ans = 0;
	for (int i = n; i >= 3; i--) {
		int j = i - 2;
		
		while (sum[i - 1] - sum[j - 1] <= a[i] && j >= 1) {
			j--;
		}
		if (j == 0) j = 1;
		if (sum[i - 1] - sum[j - 1] <= a[i]) {
			continue;
		}
		
		ans += 1;
		for (; j < i; j++) {
			int tmp = dp[i - 1] - dp[j] + 1;
			int TK = Power(j - 1) - tmp;
			if (TK < 0) TK += Mod;
			ans += TK;
			ans %= Mod;
		}
	}
	
	cout << ans;
	
	
	return 0;
}