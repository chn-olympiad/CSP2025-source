#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n;
long long ans=0;
int r1;
void dfs(int r,long long s)
{
	if(r>n)
	{
		return ;
	}
	if(r-r1>=1)
	{
		for(int i=r+1;i<=n;i++)
		{
			if(a[i]<s)
			{
				ans+=(n-i+1)%998244353;
			}
		}
	}
	for(int i=0;i<=1;i++)
	{
		if(i==1)
		{
			dfs(r+1,s+a[r]);
		}
		else
		{
			dfs(r+1,s);
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
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		long long b=1,c=1;
		for(int j=0;j<i;j++)
		{
			b*=(n-j);
			c*=(i-j);
		}
		ans=(ans+b/c)%998244353;
	}
	cout<<ans;
	return 0;
} 
