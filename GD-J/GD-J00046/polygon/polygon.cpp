#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005], td, n;
long long ans;
void dfs(int deep, long long cnt, int maxn, int c) {
	if (maxn * 2 >= cnt && c == td) return ;
	if (c == td) {
		ans++;
		ans %= mod;
		return ;
	}
	if (deep == n + 1) return ;
	dfs(deep + 1, cnt, maxn, c);
	dfs(deep + 1, cnt + a[deep], max(maxn, a[deep]), c + 1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int maxn = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		maxn = max(maxn, a[i]);
	}
	for (int i = 3; i <= n; i++) {
		td = i;
		dfs(1, 0, 0, 0);
	}
	printf("%lld", ans);
	return 0;
}
