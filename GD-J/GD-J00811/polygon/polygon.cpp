#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5005],ans;
void dfs(long long num,long long x)
{
	for(int i=x+1;i<=n;i++)
	{
		if(num<=a[i])
		{
			dfs(num+a[i],i);
			continue;
		} 
		ans=(ans+1)%MOD;
		dfs(num+a[i],i);
	}
	return;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dfs(a[i]+a[j],j);
		}
	}
	cout<<ans;
	return 0;
} 
