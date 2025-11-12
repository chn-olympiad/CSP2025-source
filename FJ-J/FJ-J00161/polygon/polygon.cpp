#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
long long ans,C[5005][5005],dp[500005],sum,a[5005];
bool vis[5005];
bool flag = true;
bool check()
{
	long long maxx = 0,s = 0;
	for(int i = 1;i <= n;i++)
	{
		if(vis[i])
		{
			maxx = max(maxx,a[i]);
			s += a[i];
		}
	}
	return s > 2*maxx;
}
void dfs(int k)
{
	if(k == n+1)
	{
		ans += check();
		return;
	}
	vis[k] = 1;
	dfs(k+1);
	vis[k] = 0;
	dfs(k+1);
}
void init()
{
	for(int i = 0;i <= n;i++) C[i][0] = C[i][i] = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j < i;j++) C[i][j] = C[i-1][j-1]+C[i-1][j];
	}
}
int f(int x,int k)
{
	long long res = 0;
	int i = x-1;
	for(int j = sum;j >= 0;j--) dp[j+a[i]] = (dp[j+a[i]]+dp[j])%mod;
	sum += a[i];
	for(int j = k+1;j <= sum;j++) res = (res+dp[j])%mod;
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		flag &= (a[i] == 1ll);
	}
	sort(a+1,a+n+1);
	if(n <= 20)
	{
		dfs(1);
		cout << ans;
	}
	else if(flag)
	{
		init();
		for(int i = 3;i <= n;i++) ans = (ans+C[n][i])%mod;
		cout << ans;
	}
	else
	{	
		dp[0] = 1;
		for(int i = 2;i <= n;i++) ans = (ans+f(i,a[i]))%mod;
		cout << ans;
	}
	return 0;
}

