#include<bits/stdc++.h>
using namespace std;
long long sum[500005],a[500005],m,f[2828][2828];
long long dfs(long long x,long long y)
{
	long long s=0;
	if((sum[y]^sum[x-1])==m)
	{
		s=1;
	}
	if(x==y)
	{
		return s;
	}
	for(long long ii=x;ii<y;ii++)
	{
		if(f[x][ii]==-1)
		{
			f[x][ii]=dfs(x,ii);
		}
		if(f[ii+1][y]==-1)
		{
			f[ii+1][y]=dfs(ii+1,y);
		}
		s=max(f[x][ii]+f[ii+1][y],s);
	}
	f[x][y]=s;
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		memset(f[i],-1,sizeof(f[i]));
	}
	cout<<dfs(1,n);
	return 0;
}
