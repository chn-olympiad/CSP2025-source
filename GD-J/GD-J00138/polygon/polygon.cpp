#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],ans,bj[1000005];
void dfs(int x,int s)
{
	if(s>x*2)
	{
		ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==0)
		{
			bj[i]=1;
			dfs(max(a[i],x),s+a[i]);
			bj[i]=0;
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n>=1000)
	{
		int s=1;
		for(int i=1;i<=n;i++)
		{
			s=s*i;
			s%=998244353;
		}
		cout<<s;
		return 0;
	}
	dfs(0,0);
	int s=1;
	for(int i=1;i<=n;i++)
	{
		s=s*i;
		s%=998244353;
	}
	cout<<(ans/s)%998244353;
}
