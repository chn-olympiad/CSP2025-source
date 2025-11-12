#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5005],s[5005];
long long ans;
void dfs(int step,int cnt,int all,int vmax)
{
	if(step>n)
	{
		if(cnt>=3&&all>vmax*2)
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	dfs(step+1,cnt,all,vmax);
	s[++cnt]=a[step];
	dfs(step+1,cnt,all+a[step],max(vmax,a[step]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int vm=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vm=max(vm,a[i]);
	}
	if(vm<=1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*2)%mod;
		}
		ans=(ans-(1+n+n*(n-1)/2)+mod)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
