#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int dp[N];
int n,m;
char a;
int s[N];
int c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a=='1')
		{
			s[i]=1;
		}
		else if(a=='0')
		{
			s[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)
			{
				printf("0\n");
				return 0;
			}
		}
		int sum=1;
		for(int i=m;i>=1;i--)
		{
			sum*=i;
		}
		printf("%d",sum%998244353);
		return 0;
	}
	if(m==1)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==1)
			{
				tot++;
			}
			if(tot>1)
			{
				printf("0\n");
				return 0;
			}
		}
		int cnt=1;
		for(int i=m;i>=1;i--)
		{
			cnt*=i;
		}
		printf("%d\n",cnt%998244353);
		return 0;
	}
	int ans=1;
	for(int i=m;i>=1;i--)
	{
		ans*=i;
	}
	printf("%d",ans%998244353);
}
