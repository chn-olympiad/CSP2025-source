#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string ttty;
int s[510],c[510],a[12],sc[510];
long long jc[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=505;i++)
	{
		jc[i]=jc[i-1]*i%mod;
	}
	int n,m;
	scanf("%d%d",&n,&m);
	cin>>ttty;
	ttty=' '+ttty;
	for(int i=1;i<=n;i++)
	{
		s[i]=ttty[i]-'0';
		scanf("%d",&c[i]);
		for(int j=c[i];j<=n;j++)
		{
			sc[j]++;
		}
	}
	if(m==1)
	{
		long long ans=1;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==1)
			{
				ans=ans*(sc[i-1]-res)%mod;
				res++;
			}
		}
		ans=ans*jc[n-res]%mod;
		ans=(jc[n]-ans+mod)%mod;
		printf("%lld",ans);
	}
	else if(m==n)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=s[i];
		}
		if(ans==n)
		{
			if(sc[0])
			{
				printf("0");
			}
			else
			{
				printf("%lld",jc[n]);
			}
		}
		else
		{
			printf("0");
		}
	}
	else
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				res++;
			}
		}
		if(res-1==n-m)
		{
			printf("%lld",jc[n-1]*res%mod);
		}
		else if(res-1>n-m)
		{
			printf("0");
		}
		else
		{
			printf("%lld",jc[n]);
		}
	}
	return 0;
}
