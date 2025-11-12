#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
long long m=998244353;
int a[5005],n;
long long g(int n,int m)
{
	m=min(m,n-m);
	int j=1;
	long long ans=1;
	for(int i=n;i>=n-m+1;i--)
	{
		ans*=1LL*i;
		if(j>m)ans%=m;
		while(ans%j==0&&j<=m)
		{
			ans/=1LL*j;
			j++;
		}
	}
	return ans;
}
long long ans;
void dfs(int x,int num)
{
	if(x>n)
	{
		return;
	}
	if(num>a[x])
	{
		int k=upper_bound(a+1,a+n+1,num-1)-a;
		k-=1;
		if(k>=x)ans++;
		ans%=m;
	}
	dfs(x+1,num+a[x]);
	dfs(x+1,num);
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
	if(a[n]==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=g(n,i);
			ans%=m;
		}
		cout<<ans;
	}
	else
	{
	    dfs(1,0);
	    cout<<ans;
	}
    return 0;
}
