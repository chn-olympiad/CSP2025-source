#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5, mod = 998244353;
int n, a[maxn];
long long ans, j = 1;
void dfs(int idx, int maxx, int cnt, long long tot) {
	if(idx > n) {
		if(tot > maxx * 2ll && cnt >= 3) ++ans;
		return ;
	}
	dfs(idx + 1, maxx, cnt, tot);
	dfs(idx + 1, max(maxx, a[idx]), cnt + 1, tot + a[idx]);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if(n <= 20) {
		dfs(1, 0, 0, 0);//idx, max, cnt, tot
		printf("%lld", ans);
		return 0;
	}
	ans = 1;
	for(int i = 1; i <= n; ++i)
		ans = (ans * 2) % mod;
	j += n;
	j %= mod;
	j += ((n - 1) * 1ll * n % mod) / 2;j %= mod;
//	cout << j << endl;
	for(int i = 1; i < n - 1; ++i)
		for(int k = i + 1; k < n; ++k) {
			j += (n - k), j %= mod;
//			cout << n - j << endl;
		}
//	cout << ans << ' ' << j << endl;
	printf("%lld", ans - j);
	return 0;
}
