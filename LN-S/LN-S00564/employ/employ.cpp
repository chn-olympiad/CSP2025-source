#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
char s[510];
int a[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int cnt=-1,flag=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			cnt=i;
			break;
		}
	}
	if(cnt==-1)
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		long long ret=1;
		for(int i=m+1;i<=n;i++)
		{
			ret=ret*i%mod;
		}
		for(int i=2;i<=n-m;i++)
		{
			ret/=i;
		}
		printf("%lld",ret);
	}
	if(m==1)
	{
		long long ret=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=cnt)
			{
				ret++;
			}
		}
		printf("%lld",ret);
	}
	else if(m==n)
	{
		if(flag==1)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	return 0;
}
