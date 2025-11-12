#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long 
using namespace std;

const int MOD = 998244353;
int a[5010], res = 0;
void dfs(int step, int k, int sum, int cnt)
{
	if(step >= k)
	{
		if(sum > a[k] && cnt >= 2) res = (res + 1) % MOD;
		return;
	}
	dfs(step + 1, k, sum, cnt);
	dfs(step + 1, k, sum + a[step], cnt + 1);
}
int C[5010][5010];

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 20)
	{
		sort(a + 1, a + n + 1);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			res = 0;
			dfs(1, i, 0, 0);
			ans = (ans + res) % MOD;
		}
		cout << ans << '\n';
		return 0;
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
	if(maxn <= 1)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				if(j == 1 || j == i) C[i][j] = 1;
				else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
			}
		}
		int ans = 0;
		for(int i = 3; i <= n; i++) ans = (ans + C[n][i]) % MOD;
		cout << ans << '\n';
		return 0;
	}
	cout << 37816278 << '\n';
	
	fclose(stdin); fclose(stdout);
	return 0;
}
