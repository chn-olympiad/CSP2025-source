#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
const int mod=998244353;
int ans=0;
void dfs(int sum,int ch,int maxx,int deep)
{
	if(deep==n)
	{
		if(ch>2&&sum>2*maxx)
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	int t=max(maxx,a[deep]);
	dfs(sum+a[deep],ch+1,t,deep+1);
	dfs(sum,ch,maxx,deep+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0,-1,0);
	cout<<ans;
	return 0;
}
