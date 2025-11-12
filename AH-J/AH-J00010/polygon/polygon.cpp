#include<bits/stdc++.h>
using namespace std;
long long m,a[5010],cnt,n;
void dfs(long long x,long long y,long long z,long long q)
{
	if(n==x)
	{
		if(z>2*q) cnt++;
		return ;
	}
	for(long long i=y+1;i<=m;i++)
	{
		n++;
		dfs(x,i,z+a[i],a[i]);
		n--;
	}
	return ;
}
int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&m);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+m+1);
	for(long long i=3;i<=m;i++)
	{
		dfs(i,0,0,0);
	}
	printf("%lld",cnt%998244353);
	return 0;
}
