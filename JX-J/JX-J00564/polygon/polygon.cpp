#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5001];
int sum[5001],sum1=0,sumans=0;
int bfs(int x)
{
	sum1++;
	sum[sum1]=a[x];
	sumans+=a[x];
	if(sum1>=3)
	{
		if(sumans>a[x]*2) 
		{
			ans++;
			ans=ans%998244353;
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		bfs(i);
	}
	sum1--;
	sumans-=a[x];
	return 0;
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
	bfs(1);
	cout<<ans;
	return 0;
}
