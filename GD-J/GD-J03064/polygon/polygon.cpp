#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 5010;
int dp[maxn][maxn],a[maxn],n,ans;
int qpow(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)res = res * a % mod;
		a = a * a % mod;b >>= 1;
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1);dp[0][0] = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j <= 5000;j++)dp[i][j] = dp[i - 1][j];
		for(int j = a[i];j <= 5000;j++)dp[i][j] = (dp[i - 1][j - a[i]] + dp[i][j]) % mod;
	}
	for(int i = 1;i <= n;i++)
	{
		int num = qpow(2,i - 1);
		for(int j = 0;j <= a[i];j++)num = (num - dp[i - 1][j] + mod) % mod;
		ans = (ans + num) % mod;
	}
	cout << ans << '\n';
	return 0;
}

/*
也是用不到40min填补了自己CSP-J2023年T3没调出来和CSP-J2024年没进复赛的遗憾啊。
这个T4和ICPC 2025 Xian Region的签到题好像啊。 
*/
