#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5010];
long long ans;
void dfs(int now,int sum,int maxx)
{

	if(now>n)
	{
		if(sum>(2*maxx))
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	int da=max(maxx,a[now]);
	dfs(now+1,sum+a[now],da);
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