#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[5005],n,ans;
int f(int n)
{
	int ans=1;
	for(int i=1;i<=n;i++)ans*=i;
	return ans%mod;
}
int c(int b,int a)
{
	return f(b)/f(a)/f(b-a);
}
void dfs(int i,int s,int ax,int ch)
{
	if(i==n+1)
	{
		if(ax*2<s&&ch>=3)ans++;
		return;
	}
	dfs(i+1,s+a[i],max(ax,a[i]),ch+1);
	dfs(i+1,s,ax,ch);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	if(s.size()==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=c(n,i)%mod;
			ans%=mod;
		}
	}
	else 
	{
		dfs(1,0,0,0);
	}
	cout<<ans%mod;
	return 0;
}//1042392
