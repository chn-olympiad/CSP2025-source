#include<bits/stdc++.h>
using namespace std;

int c[505],v[505],a[505];
char s[505];
int n,m;
long long ans=0;
long long mod=998244353;
void dfs(int st)
{
	if (st==n+1)
	{
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (cnt>=c[a[i]]||s[i]=='0')
			{
				cnt++;
			}
		}
		cnt=n-cnt;
		ans+=(cnt>=m);
		ans%=mod;
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (!v[i])
		{
			a[st]=i;
			v[i]=1;
			dfs(st+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

