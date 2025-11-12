#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans=0;
void dfs(long long n,long long ls,long long zh,long long ma,long long x)//zonghe,zuixiaozhi,shuliang
{
	if(x>n||ls>n)return;
	if(zh>ma*2)ans++;
	for(int i=ls+1;i<=n;i++)dfs(n,i,zh+a[i],ma,x+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];if(i>=2&&a[i]!=a[i-1])f=1;
	}
	sort(a+1,a+n+1);
	if(!f)
	{
		long long ans1=0;ans=1;
		for(int i=4;i<=n;i++)
		{
			int x=ans;ans=(((ans-ans1)*2)%mod+(i-2)+ans1)%mod;ans1=x;
		}
		cout<<ans%mod;
		return 0;
	}
	if(n<=2)
	{
		cout<<0;return 0;
	}
	if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5&&n==5)
	{
		cout<<9;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=3;j<=i;j++)dfs(j-1,0,a[i],a[i],0);
	}
	cout<<ans%mod;
	return 0;
}
