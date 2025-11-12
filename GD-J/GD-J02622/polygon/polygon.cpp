#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long n,a[5003],ans,cnt[5003];
void dfs(long long x,long long sum,long long mx)
{
	if(x == n + 1)
	{
		if(sum - mx > mx)
		{
			ans++;
			ans = ans % 998244353;
		}
		return;
	}
	if(mx * 2 > (sum + cnt[n] - cnt[x - 1]))
	{
		return;
	}
	dfs(x + 1,sum + a[x],max(mx,a[x]));//1
	dfs(x + 1,sum,mx);//0
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cnt[i] = cnt[i - 1] + a[i];
	}
	dfs(1,0,0);
	cout << ans % 998244353;
	return 0;
}
