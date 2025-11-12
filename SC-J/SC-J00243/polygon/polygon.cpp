#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
int a[5010];
long long ans;
inline bool maxx(int a, int b)
{
	return (a > b) ? a : b;
}
void dfs(int maxn, int sum, int sl, int id)
{
	if((maxn << 1) < sum && sl > 2)
	{
		ans++;
		ans %= mod;
	}
	for(int i = id + 1;i <= n;i++)
	{
		dfs(maxx(maxn, a[i]), a[i] + sum, sl + 1, i);
	}
}
//dp[i]表示选i根有多少种方式 
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i]);
	}
	if(n <= 50)
	{
		dfs(0, 0, 0, 0);
	}
	else
	{
		for(int i = 3;i <= n;i++)
		{
			long long fop = 1;
			for(int j = 1;j <= i;j++)
			{
				fop *= (n - j + 1);
				fop %= mod;
			}
			for(int j = 1;j <= i;j++)
			{
				fop /= j;
			}
			ans += fop;
			ans %= mod;
		}
//		printf("%lld\n", ans);
	}
	printf("%lld", ans);
//	node lpm;
//	lpm.maxn = 0;
//	lpm.sum = 0;
//	memset(lpm.st, false, sizeof(lpm.st));
//	for(int i = 1;i <= 500;i++)
//	{
//		dp[0].push_back(lpm);
//	}
//	for(int i = 0;i <= n;i++)
//	{
//		for(int j = 1;j <= n;j++)
//		{
//			if(dp[i][cnt[i]].st[j])
//			{
//				continue;
//			}
//			if(dp[i][cnt[i]].maxn >= a[j])
//			{
//				cnt[i + 1]++;
//				node xj;
//				xj.maxn = dp[i][cnt[i]].maxn;
//				xj.sum = dp[i][cnt[i]].sum + a[j];
//				for(int k = 1;k <= n;k++)
//				{
//					xj.st[k] = dp[i][cnt[i]].st[k];
//				}
//				xj.st[j] = true;
//				dp[i + 1].push_back(xj);
//			}
//			else if(a[j] < dp[i][cnt[i]].sum)
//			{
//				cnt[i + 1]++;
//				node xj;
//				xj.maxn = a[j];
//				xj.sum = dp[i][cnt[i]].sum + a[j];
//				for(int k = 1;k <= n;k++)
//				{
//					xj.st[k] = dp[i][cnt[i]].st[k];
//				}
//				xj.st[j] = true;
//				dp[i + 1].push_back(xj);
//			}
//		}
//	}
//	long long ans = 0;
//	for(int i = 3;i <= n;i++)
//	{
//		ans += dp[i].size();
//		ans %= 998244353;
//	}
//	printf("%lld", ans);
	return 0;
}
/*
有点像dp？？？ 
还是n^2的？？？ 
但我不会 /ll 
坏了n^3没调出来
写爆搜去了   
*/
