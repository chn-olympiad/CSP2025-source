#include<bits/stdc++.h>
using namespace std;
int n,k,maxn=-1;
int a[1000010];
int dg(int x,int l)
{
	int c=0;
	int s=0;
	for(int i=x;i<x+l;i++)
	{
		s=s^a[i]; 
	}
	if(s==k)
	{
		c++;
	}
	int z=c;
	for(int i=x+l;i<=n;i++)
	{
		for(int t=1;t<=n-i+1;t++)
		{
			c=max(c,z+dg(i,t));
		}
	}
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int t=1;t<=n-i+1;t++)
		{
			maxn=max(maxn,dg(i,t));
		}
	}
	printf("%d",maxn);
	return 0;
}
