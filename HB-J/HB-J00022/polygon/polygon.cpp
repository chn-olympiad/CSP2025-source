#include<bits/stdc++.h>
using namespace std;
int n;long long a[5005],ans;
void dfs(int k,long long s,long long maxx)
{
	if(k>n)
	{
		if(s>2*maxx)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(k+1,s,maxx);
	dfs(k+1,s+a[k],max(maxx,a[k]));
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
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
