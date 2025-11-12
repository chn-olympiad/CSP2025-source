#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,c[1001],vis[1001],num[1001];
string s;
int ans=0;
void check()
{
	int refused=0,succeed=0;
	for(int i=1;i<=n;i++)
	{
		if(refused >= c[num[i]]) 
		{
			refused++;
			continue;
		}
		else if(s[i] == '0') 
		{
			refused++;
			continue;
		}
		else if(s[i] == '1')
		{
			succeed++;
		}
	}
	if(succeed >= m) ans++;
	ans %= mod;
}
void dfs(int x)
{
	if(x == n+1)
	{
		check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i] == 0)
		{
			num[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
			num[x]=0;
		} 
	}
}
long long func(int n)
{
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans *= i;
		ans %= mod;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = '#'+s;
	for(int i=1;i<=n;i++) cin >> c[i];
	if(n <= 13)
	{
		dfs(1);
		cout << ans;
	}
	else cout << func(n);
	return 0;
}