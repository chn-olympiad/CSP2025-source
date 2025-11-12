#include<bits/stdc++.h>
using namespace std;
int n,a[5005],viss;
long long ans;
void dfs(int now,int sum,int maxx,int times)
{
	if(now==n+1)
	{
		if(sum>2*maxx)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	if(n-now+1>=3-times)
	{
		dfs(now+1,sum+a[now],max(maxx,a[now]),times+1);
		dfs(now+1,sum,maxx,times);	
	}
	else
		dfs(now+1,sum+a[now],max(maxx,a[now]),times+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
			`viss=1;
	}
	if(!viss)
	{
		unsigned long long dui=1;
		for(int i=1;i<=n;i++)
		{
			dui*=2;
			dui%=998244353;
		}
		dui=dui-1-n-n*(n-1)/2;
		if(dui<0)
			dui+=998244353;
		cout<<dui;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
} 