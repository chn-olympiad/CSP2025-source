#include<iostream>
#include<cstdio>
using namespace std;
#define mod 998244353
long long a[5005];
long long ans;
int n;
void dfs(int now,long long sum,long long maxx)
{	
	if(now>n)
	{
		if(sum>2*maxx)
		ans++;
		ans%=mod;
		return;
	}
	dfs(now+1,sum+a[now],max(maxx,a[now]));
	dfs(now+1,sum,maxx);
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
	dfs(1,0,0);
	cout<<ans;
	return 0;
}