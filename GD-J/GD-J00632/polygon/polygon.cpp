#include <bits/stdc++.h>
using namespace std;

long long a[5005] = {};
long long n;

bool cmp(long long x,long long y)
{
	return x > y;
}

long long c(long long y,long long x)
{
	long long s = 1;
	if (x == y)
	{
		return 1;
	}
	if (x == 0)
	{
		return 1;
	}
	if (y == 0)
	{
		return 0;
	}
	for(long long i = y;i <= y - x + 1;i++)
	{
		s = s * i;
	}
	for(long long i = 1;i <= x;i++)
	{
		s = s / i;
	}
	return s;
}

long long dfs(long long cnt,long long step,long long target,long long sum,long long x)
{
	long long ans = 0;
	if (x > n || step > cnt + 1)
	{
		return 0;
	}
	if (sum > target)
	{
		return c(min(cnt - step + 2,n - x),cnt - step + 1);
	}
	else
	{
		for(long long i = x + 1;i <= n;i++)
		{
			ans += dfs(cnt,step + 1,target,sum + a[i],i);
			ans = ans % 998244353;
		}
	}
	return ans % 998244353;
}

int main()
{
	long long ans = 0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(long long i = 1;i <= n - 2;i++)
	{
		for(long long j = 1;j <= n - i + 1;j++)
		{
			ans += dfs(j,2,a[i] * 2,a[i],i);
			ans = ans % 998244353;
		}
	}
	ans = ans % 998244353;
	cout << ans;
	return 0;
} 
