#include<iostream>
using namespace std;
int n,m[5005]={};
int s[5005]={},exs=0;
int h=0;
int y(int a,int st,int x)
{
	if(st==n-1)
	{
		if(h>(x*2))
		{
			exs++;
		}		
		return 1;
	}
	if(a>=3)
	{
		if(h>(x*2))
		{
			exs++;
		}
	}
	for(int i=st+1;i<n;i++)
	{
		h+=m[i];
		if(m[i]>x)
		{
			y(a+1,i,m[i]);
		}
		else
		{
			y(a+1,i,x);
		}
		h-=m[i];
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int k=0;k<n;k++)
	{
		cin>>m[k];
	}
	y(0,-1,0);
	exs=exs%998244353;
	printf("%d",exs);
	return 0;
 } 
