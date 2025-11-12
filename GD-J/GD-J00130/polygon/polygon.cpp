#include<bits/stdc++.h>
using namespace std;
int n,a[5005],bz[5005],maxx,y,ans;
void dfs(int x,int s,bool p)
{
	if(s>maxx&&p==1)
	{
		ans=(ans+1)%998244353;
	}
	if(x==y+1)
	{
		return;
	}
	if(bz[x]==0)
	{
		bz[x]=1;
		dfs(x+1,s+a[x],1);
		bz[x]=0;
	}
	dfs(x+1,s,0);
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
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--)
	{
		maxx=a[i];
		y=i-1;
		dfs(1,0,0);
	}
	cout<<ans;
	return 0;
}
