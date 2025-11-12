#include<bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int n, ans;
long long a[N], sum[N], c[N][N];
bool v[N];
void dfs(int x) {
	if(x == n+1) {
		int cnt = 0;
		long long Max = 0, val = 0;
		for(int i = 1; i <= n; i++)
			if(v[i] == true) val += a[i], Max = max(Max, a[i]), cnt++;
		if(val > 2 * Max && cnt >= 3) ans++;
		ans %= mod;
		return ;
	}
	dfs(x+1);
	v[x] = true;
	dfs(x+1);
	v[x] = false;
}
void solve()
{
	c[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j], c[i][j] %= mod;
	for(int i = 3; i <= n; i++) ans += c[n][i];
	printf("%lld", ans);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	bool ok = true;
	for(int i = 1; i <= n; i++)
		if(a[i] != 1) ok = false;
	if(ok == true) solve();
	else {
		dfs(1);	
		printf("%lld", ans);
	}
	
	return 0;
}
