#include<bits/stdc++.h>
using namespace std;
int n,a[5111];
long long b[5111];
long long d(int x,int i)
{
	long long s=1,su=1;
	for(int j=0;j<i;j++)
	{
		s*=x-j;
		su*=i-j;
	}
	return (s/su)%998244353;
}
long long df(int x)
{
	if(b[x]) return b[x];
	long long sum=0;
	for(int i=1;i<=x;i++)
	{
		sum+=d(x,i)%998244353;
	} 
	b[x]=sum;
	return b[x];
}
long long dfs(int i,int x,int j)
{
	if(x>a[i]*2)
	{
		return df(j-1)%998244353+1;
	}
	long long ans=0;
	for(int k=j-1;k>=1;k--)
	{
		ans+=dfs(i,x+a[k],k)%998244353;
	}
	return ans;
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
	long long ans=0;
	for(int i=n;i>=1;i--)
	{
		ans+=dfs(i,a[i],i) % 998244353;
	}
	cout<<ans;
	return 0;
}


