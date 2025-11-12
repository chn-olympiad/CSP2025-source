#include<bits/stdc++.h>
using namespace std;
int n,m;//n应聘人数,m录用人数
char s[1000];
int c[1000];
long long ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int shu0=0;
	for(int i=0;i<=n;i++)
	{
		scanf("%c",&s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			shu0+=1;
		}
	}
	int jl0=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			jl0++;
		}
	}
	if(n-shu0<m)
	{
		ans=0;
	}
	else
	{
		ans=1;
		if(jl0==0)
		{
			for(int i=0;i<n;i++)
			{
				ans=(ans*(n-shu0-i))%998244353;
			}
		}
		else if(m==1)
		{
			if(s[1]=='1')
			{
				for(int i=0;i<n;i++)
				{
					ans=(ans*(n-shu0-i))%998244353;
				}
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}