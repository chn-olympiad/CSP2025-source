#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, a[N], sum, ma, ans;
void dfs(int now, int ma) {
	if (now > n) {
		if (sum != 0) {
			if (sum > ma * 2) ans++;
			ans %= 998244353;
		}
		return ;
	}
	sum += a[now];
	dfs(now + 1, max(ma, a[now]));
	sum -= a[now];
	dfs(now + 1, ma);
}
signed main() { 
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) ma = max(ma, a[i]);
//	if (ma == 1) {
//		int cnt = 1;
//		for (int i = 3; i <= n; i++) {
//			cnt = 1;
//			for (int j = 1; j <= i; j++) {
//				cnt = (cnt * ())
//			}
//		}
//	}
	dfs(1, -1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 
1 2 3 4 5

5
2 2 3 8 10

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
