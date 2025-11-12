#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],ans;
void dfs(int s,int t,int m,long long sum)
{
	if(t>m)
	{
		if(sum>b[m]*2) ans=(ans+1)%998244353;
		return;
	}
	else
	{
		for(int i=s; i<=n; i++)
		{
			b[t]=a[i];
			dfs(i+1,t+1,m,sum+a[i]);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n<3)
	{
		printf("0\n");
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
		{
			printf("1\n");
			return 0;
		}
		else
		{
			printf("0\n");
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=3; i<=n; i++)
	{
		dfs(1,1,i,0);
	 } 
	 printf("%lld\n",ans%998244353);
	return 0;
}
