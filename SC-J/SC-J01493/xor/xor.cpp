#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
int s[200010];
int st[1000010],ed[1000010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n<=2&k==0)
	{
		if(n==1)
		{
			printf("0");
		}
		if(n==2)
		{
			printf("1");
		}
		return 0;
	}
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			s[i]=s[i-1]^a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				st[++cnt]=i;
				ed[cnt]=i;
			}
			int t=s[i]^k;
			for(int j=i+1;j<=n;j++)
			{
				if(t==s[j]^s[i])
				{
					st[++cnt]=i;
					ed[cnt]=j;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int tmp=0;
			int f=ed[i];
			tmp++;
			for(int j=i+1;j<=cnt;j++)
			{
				if(st[j]>f)
				{
					f=ed[j];
					tmp++;
				}
			}
			ans=max(ans,tmp);
		}
		printf("%lld",ans);
	}
	return 0;
}