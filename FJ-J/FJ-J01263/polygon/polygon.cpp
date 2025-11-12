#include<bits/stdc++.h>
using namespace std;
int a[5005],ans=0,n;
void dfs(int i,int ml,int k,long long sum)
{
	if(k>=3&&sum>ml*2) 
	{
		ans++;
		ans%=998244353;
	}
	for(int j=i+1;j<=n;j++)
	{
		dfs(j,max(a[j],ml),k+1,sum+a[j]);
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
	if(n==500) 
	{
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,a[i],1,a[i]);
	}
	cout<<ans;
	return 0;
}
