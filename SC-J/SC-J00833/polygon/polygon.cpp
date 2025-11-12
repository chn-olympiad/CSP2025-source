#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5001];
bool vis[5001];
void dfs(int x,int sum,int num,int maxx,int polygon) 
{
	if(sum==polygon)
	{
		if(num>maxx*2)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(i+1,sum+1,num+a[i],max(maxx,a[i]),polygon);
			vis[i]=0;
		}
	}
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
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			vis[j]=1;
			dfs(j,1,a[j],a[j],i);
			vis[j]=0;
		}
	}
	cout<<ans;
	return 0;
}