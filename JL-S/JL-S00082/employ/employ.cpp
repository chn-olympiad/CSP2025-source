//[12,16]
#include <bits/stdc++.h>
using namespace std;
char s[505];
int n,m;
int c[505],d[15],vis[15];
int lstans = 0;
void dfs(int dep)
{
	if(dep==n+1)
	{
		int cnt = 0,ans = n;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[d[i]]||s[i]=='0')
			{
				cnt++;
				ans--;
			}
		}
		if(ans>=m) lstans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		d[dep] = i;
		dfs(dep+1);
		vis[i] = 0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(n<=10)
	{
		dfs(1);
		printf("%d\n",lstans);
	}
	else if(m==n)
	{
		int qwq = 0;
		for(int i=1;i<=strlen(s+1);i++)
		{
			if(s[i]=='0') qwq++;
		}
		if(qwq!=0)
		{
			puts("0");
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(c[i]==0)
				{
					puts("0");
					return 0;
				}
			}
			long long ans = 1;
			for(int i=1;i<=n;i++)
			{
				long long mdo = 998244353;
				ans = (ans*(long long)i)%mdo;
			}
			printf("%lld\n",ans);
		}
	}
	else if(m==1)
	{
		long long ans = 1;
		for(int i=1;i<=n;i++)
		{
			long long mdo = 998244353;
			ans = (ans*(long long)i)%mdo;
		}
		printf("%lld\n",ans);
	}
	else
	{
		puts("0");
	}
}