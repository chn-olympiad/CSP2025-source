#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[25],ans;
int n;
void dfs(int now,int sum,int maxx)
{
	if(now==n+1)
	{
	//	cout<<sum<<' '<<maxx<<'\n';
		if(sum>2*maxx) ans=(ans+1)%mod;
		return;
	}
	dfs(now+1,sum+a[now],max(maxx,a[now]));
	dfs(now+1,sum,maxx);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}