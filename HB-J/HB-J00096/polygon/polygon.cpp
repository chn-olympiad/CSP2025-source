#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[5005];
void dfs(int ut,int maxx,int sum,int step)
{
	if(step>=3&&sum>2*maxx)
	{
		ans=(ans+1)%998244353;
	}
	for(int i=ut+1;i<=n;i++)
	{
		dfs(i,max(maxx,a[i]),sum+a[i],step+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dfs(i,a[i],a[i],1);
	}
	cout<<ans;
	return 0;
}
