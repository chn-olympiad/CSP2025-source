#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n,ans,mxn;
void dfs(int mx,int sum,int p)
{
	if(sum>mx*2) 
	{
		ans++;
		ans%=998244353;
	}
	for(int i=p+1;i<=n;i++)
	{
		dfs(max(mx,a[i]),sum+a[i],i);
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
		mxn=max(mxn,a[i]);
	}
	if(mxn==1)
	{
		long long ct=0,num;
		for(int i=3;i<=n;i++)
		{
			num=1;
			for(int j=n;j>=n-i+1;j--)
			{
				num*=j;
			}
			for(int j=1;j<=i;j++)
			{
				num/=j;
			}
			ct+=num;
			ct%=998244353;
		}
		cout<<ct;
	}
	else
	{
		dfs(0,0,0);
		cout<<ans;
	}
	return 0;
}
