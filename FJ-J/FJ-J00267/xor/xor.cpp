#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],b[500005],m;
void dfs(int h,int sum)
{
	if(n-h+sum<m)return ;
	for(int i=h+1;i<=n;i++)
	{
		if(b[i]!=0x3f3f3f3f3f3f3f3f)dfs(i+b[i],sum+1);
	}
	m=max(m,sum);
	return ;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		int z=a[i];
		if(z==k)
		{
			b[i]=0;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			z=(z|a[j])-(z&a[j]);
			if(z==k)
		    {
			    b[i]=j-i;
	    		break;
	    	}
		}
	} 
	for(int i=1;i<=n;i++)
	{
		if(n-m>=i)dfs(i+b[i],1);
	}
	printf("%lld",m);
	return 0;
}
