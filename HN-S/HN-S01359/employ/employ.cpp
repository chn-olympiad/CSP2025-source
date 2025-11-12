#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int Mod=998244353;

char str[600];

int c[600];

int n,m;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(m==n)
	{
		bool flag=false;
		for(int i=1;i<=n;i++)
		if(str[i]==0)
		{
			flag=true;
			printf("0\n");
		}
		if(!flag)
		{
			for(int i=1;i<=n;i++)
			{
				if(c[i]==0)
				{
					flag=true;
					printf("0\n");
				}
			}
			if(!flag)
			{
				long long ans=1;
				for(int i=2;i<=n;i++)
				ans=ans*i%Mod;
				printf("%lld\n",ans);
			}
		}
	}
	else
	{
				long long ans=1;
				for(int i=2;i<=n;i++)
				ans=ans*i%Mod;
				printf("%lld\n",ans);
		
	}
	return 0;
}
