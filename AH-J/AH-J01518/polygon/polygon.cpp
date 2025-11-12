#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long s,n;
void dfs(long long ma,long long t,long long m)
{
	if(t>ma*2)
	{
		s++;
		s=s%998244353;
	}
	for(long long i=m+1;i<=n;i++)
	{
		dfs(a[i],t+a[i],i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i;
	long long pian=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) pian=1;
	}
	if(pian==0)
	{
		cout<<n*(n-1)*(n-2)/6%998244353;
		return 0;
	}
	if(n<=20)
	{
		sort(a+1,a+n+1);
		dfs(0,0,0);
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<s;
	return 0;
}
