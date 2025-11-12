#include <bits/stdc++.h>
using namespace std;
int s[510];
int MOD = 998244353,ans,a[510],firstn = 1e9,num;
bool vis[510];
int whe[510];
int n,m;
bool check()
{
	int go = 0;
	for(int i = 1;i <= n;i ++)
	{
		int now = whe[i];
		if(a[now] <= go)
		{
			go ++;
			continue;
		}
		if(s[i] == 0)
		{
			go ++;
			continue;
		}
	}
	for(int i = 1;i <= n;i ++)
		vis[i] = 0;
	return (n - go >= m);
}
void dfs(int now)
{
	vis[now] = 1;
	bool o = 1;
	for(int i = 1;i <= n;i ++)
	{
		if(!vis[i])
		{
			whe[now] = i;
			vis[i] = 1;
			dfs(now + 1);
			o = 0;
		}
	}
	if(now == n)
	{
		if(check())
			ans = (ans + 1) % MOD;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	char c;
	bool f = 1;
	int i = 0;
	for(int i = 0;i < n;i ++)
	{
		scanf("%c",&c);
		if(c == '0')
			f = 0;
		s[i] = c - '0';
		if(c == '1')
			firstn = min(firstn,i);
	}
	if(m == n && !f)
	{
		printf("0");
		return 0;
	}
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]),num += (a[i] == 0) ? 1 : 0;
	if(n - num < m)
	{
		printf("0");
		return 0;
	}
	if(f)
	{
		int x = 1;
		for(int i = 2;i <= n;i ++)
			x = x * i % MOD;
		printf("%d",x);
		return 0;
	}
	if(m == 1)
	{
		int x = 1;
		for(int i = 2;i <= n - 1;i ++)
			x = x * i % MOD;
		for(int i = 1;i <= n;i ++)
		{
			if(a[i] > firstn)
				ans = (ans + x) % MOD;
		}
		printf("%d",ans);
		return 0;
	}
	dfs(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
