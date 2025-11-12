#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,mod=998244353;
bool flag=0;
void dfs(int x,int u,int max,long long s)
{
	if(x==0)
	{
		if(s>2*max) ans++;
		ans%=mod;
		return ;
	}
	for(int i=u+1;i<=n;++i)
	{
		dfs(x-1,i,a[i],s+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0)
	{
		long long v=n;
		for(int i=3;i<=n;++i)
		{
			v*=(n-i+1);
			v%=mod;
			ans+=v;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;++i)
	{
		dfs(i,0,0,0);
	}
	cout<<ans;
	return 0;
}
