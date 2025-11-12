#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],n,k,ans,maxn=-1,ii=0;
bool f1=1,f2=1;
void dfs(long long x,long long sum)
{
	maxn=max(maxn,sum);
	for(long long i=x+1;i<=n;i++)
	{
		if(b[i]<0x3f3f3f3f)
			dfs(b[i],sum+1);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	memset(b,0x3f3f3f3f,sizeof(b));
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) f1=0;
		if(a[i]!=1&&a[i]!=0) f1=f2=0;
	}
	if(k!=0&&k!=1) f1=f2=0;
	if(k!=0) f1=0;
	if(f1)
	{
		printf("%lld",n/2);
		return 0;
	}
	if(f2)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
					ans++;
				if(a[i]==1&&a[i+1]==1)
				{
					ans++;
					i++;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
					ans++;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		bool f=0;
		long long x=0;
		for(long long j=i;j<=n;j++)
		{
			if(a[j]==k)
				break;
			x=x^a[j];
			if(x==k)
			{
				b[i]=min(b[i],j);
				break;
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(b[i]<0x3f3f3f)
			dfs(b[i],1);
		if(a[i]==k)
			ans++;
	}
	printf("%lld",maxn+ans);
	return 0;
}
