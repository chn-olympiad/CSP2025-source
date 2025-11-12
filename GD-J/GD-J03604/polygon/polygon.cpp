#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],v[5005],ans;
void dfs(long long xb,long long m,long long max1,long long num)//xb当前下标 m长度 max1已选多边形最大值 
{
	if(m >= 3 && num>2*max1)
	{
		ans=(ans+1)%998244353;
	}
	if(xb > n)
	{
		return;
	}
	for(int i = xb+1;i <= n;i++)
	{
		if(v[i]==0)
		{
			v[i] = 1;
			max1 = max(max1,a[i]);
			dfs(i,m+1,max1,num+a[i]);
			v[i] = 0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
