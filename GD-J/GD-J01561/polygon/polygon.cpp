#include<bits/stdc++.h>
using namespace std;
long long n,mod = 998244353,a[5005],dp[5005][5005];
int cmp(int x,int y)
{
	return x < y;
}
long long dfs(int s,int i,int j,int ans)
{
	if(s > i)
	{
		if(ans > a[j])
			return 1;
		else
			return 0;
	}
	int num = 0;
	for(int k = s;k <= j-i+s;k++)
	{
		ans += a[k];
		if(ans > a[j])
		{
			num++;
			ans -= a[k];
			continue;
		}
		num = (num + dfs(s+1,i,j,a[k]))%mod;
		ans -= a[k];
	}
	return num;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int num;
		cin >> num;
		a[num] = num;
	}
	sort(a+1,a+1+n,cmp);
	n = 1;
	while(a[n] != 0)
		n++;
	n--;
	for(int i = 3;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
			dp[i][j] = (dp[i-1][j]+dp[i][j-1]+dfs(1,i-1,j,0)) % mod;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
