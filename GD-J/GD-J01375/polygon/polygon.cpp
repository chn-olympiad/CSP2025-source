#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005, MOD = 998244353;
int n, a[N], ans;
void dfs(int x, int l, int c){
	if (c >= 3 && l > a[x - 1] * 2){
		ans++;
		ans %= MOD;
	}
	if (x == n + 1){
		return;
	}
	dfs(x + 1, l + a[x], c + 1);
	dfs(x + 1, l, c);
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (n <= 20){
		dfs(1, 0, 0);
		printf("%lld", ans);
	}else{
		int ans = 0, sum = n * (n - 1) * (n - 2) * (n - 3) / 24 % MOD;
		for (int i = 4; i <= n; i++){
			ans += sum;
			ans %= MOD;
			sum = sum * (n - i) / (i + 1) % MOD;
		}
		printf("%lld", ans);
	}
	return 0;
}
