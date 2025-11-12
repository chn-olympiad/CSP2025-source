#include<bits/stdc++.h>
using namespace std;

int M=998244353;
int a[5005]={},ans=0;
int n;
//          h      s    ma       i

void dfs(int x,int t,int maxn,int y,int s)
{
	if(t>=s)
	{
		if(x>(maxn*2))
		{
			ans=(ans+1)%M;
		}
	}
	for(int i=y;i<=n;i++)
	{
		int maxn=max(maxn,a[i]);
		dfs(x+a[i],t+1,maxn,i,s);
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	for(int i=3;i<=n;i++)
	{
		for(int l=1;l<=n;l++)
		{
			dfs(a[l],0,a[l],l,i);
		}
	}
	cout<<sqrt(n*n*n);
	return 0;
 } 
