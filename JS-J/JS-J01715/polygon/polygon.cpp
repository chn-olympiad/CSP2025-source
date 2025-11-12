#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],t,one;
void dfs(int k,long long sum,int maxx,int num)
{
	if(k>n)
	{
		if(sum>maxx*2&&num>=3)
			t=(t+1)%998244353;
		return;
	}
	for(int i=1;i>=0;i--)
	{
		if(i==1)
		{
			if(a[k]>maxx)
				dfs(k+1,sum+a[k],a[k],num+1);
			else
				dfs(k+1,sum+a[k],maxx,num+1);
		}
		if(i==0)
		{
			dfs(k+1,sum,maxx,num);
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
		one=max(one,a[i]);
	}
	if(one<=1)
	{
		t=1;
		for(int i=1;i<=n;i++)
			t=t*2%998244353;
		t=t-1-n-n*(n-1)/2;
		if(t<0)
			t=t+998244353;
		cout<<t;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<t;
	return 0;
}