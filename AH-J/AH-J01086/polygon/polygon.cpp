#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long n,cnt,ans[5005];
void dfs(long long id,long long sum,long long num)
{
	if(num>=3&&sum>2*a[id]) 
	{
		cnt++;
	}
	for(long long i=id+1;i<=n;i++)
	{
		dfs(i,sum+a[i],num+1);
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
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		dfs(i,i,1);
	}
	cout<<cnt%998244353;
	return 0;
}
