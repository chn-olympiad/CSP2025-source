#include<bits/stdc++.h>
using namespace std;
int n,a[50005];
bool vis[50005];
bool check(int x)
{
	return x>=0&&x<n&&!vis[x];
}
void dfs(int x,int add,int tmax,int count)
{
	if(add>2*tmax)
	{
		count++;
		return ;
	}
	if(n==0)
	{
		return ;
	}
	for(int i=0;i<x;i++)
	{
		if(check(i))
		{
			vis[i]=1;
			dfs(x-1,add+=a[i],tmax=max(a[i],tmax),count);
			vis[i]=0;
		}
	}
	if(x==n)
	{
		cout<<count;
		return;
	}
}
int main()
{
	freopen("polyon.in","R",stdin);
	freopen("polyon.out","W",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dfs(n,0,0,0);
	return 0;
}
