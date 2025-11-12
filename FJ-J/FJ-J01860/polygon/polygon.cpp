#include <bits/stdc++.h>
using namespace std;
long long a[5005],n,cnt[50005],dp[5005],sum[50005],ans;
const long long MAXN = 50000;
const long long MOD = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i = 1;i <= n;i++)
	    cin >> a[i];
	sort(a + 1,a + n + 1);
	cnt[0] = 1;
	cnt[a[1]] = 1; 
	dp[3] = ((a[1] + a[2]) > a[3]);
	for (long long i = 2;i <= n;i++)
	{ 
	    for (long long j = MAXN;j >= a[i];j--)
	        cnt[j] = (cnt[j - a[i]] + cnt[j]) % MOD;
	    if (i > 3)
	        dp[i] = (dp[i - 1] + (sum[MAXN] - sum[a[i]] + MOD) % MOD) % MOD;
		for (long long j = 1;j <= MAXN;j++) 
	        sum[j] = (sum[j - 1] + cnt[j]) % MOD; 
	} 
	cout << dp[n] % MOD;
} 
