#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
bool vis[505];
char s[505];
long long ans;
void dfs(int x,int lr)
{
	if(x>n)
	{
		if(n-lr>=m)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(s[x]=='0')
			{
				vis[i]=1;
				dfs(x+1,lr+1);
				vis[i]=0;
			}
			else
			{
				if(lr>=a[i])
				{
					vis[i]=1;
					dfs(x+1,lr+1);
					vis[i]=0;
				}
				else
				{
					vis[i]=1;
					dfs(x+1,lr);
					vis[i]=0;
				}
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				printf("0");
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==1)
	{
		int mark=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				mark=1;
			}
		}
		if(mark==1)
		{
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
			printf("%lld",ans);
			return 0;
		}
		else
		{
			printf("0");
			return 0;
		}
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}

