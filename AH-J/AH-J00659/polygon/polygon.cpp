#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],t[1000005];
int MOD=998244353;
int n,gh=0;
void dfs(int i)
{
	if (i>n)
	{
		int sum=0,xr=1;
		for(int i=n;i>=1;i--)
		{
			if (t[i]) 
			{
				sum+=xr*a[i];
				if (xr==1) xr=-1;
			}
		}
		gh+=(sum<0);
		gh%=MOD;
		return;
	}
	t[i]=1;
	dfs(i+1);
	t[i]=0;
	dfs(i+1);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=-1;
	for(int i=1;i<=n;i++)
		cin>>a[i],mx=max(mx,a[i]);
	if (mx==1)
	{
		int sm=0,f1=6,f2=n;
		f2*=(n-1);
		f2%=MOD;
		f2*=(n-2);
		f2%=MOD;
		for(int i=4;i<=n;i++)
		{
			f1*=i;
			f1%=MOD;
			f2*=(n-i+1);
			f2%=MOD;
			sm+=f2/f1;
			sm%=MOD;
		}
		cout<<sm;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<gh;
	return 0;
}
