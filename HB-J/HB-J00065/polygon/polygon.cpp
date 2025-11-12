#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],h[5005],ans;
bool op;
void dfs(int x,int y)
{
	if(y==0)return ;
	if(x-a[y]>0)
	{
		ans++;
		ans%=998244353;
		dfs(x-a[y],y-1);
	}
	if(x-a[y]==0)
	{
		ans++;
		ans%=998244353;
	}
	dfs(x,y-1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)op=1;
	}
	if(!op)
	{
		ll t=0;
		for(int i=3;i<=n;i++)
		{
			ll a=1;
			for(int j=1;j<=i;j++)
			{
				a*=(n-j+1);
				a/=j;
			}
			a%=998244353;
			t+=a;
			t%=998244353;
		}
		cout<<t;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)h[i]=h[i-1]+a[i];
	for(int i=3;i<=n;i++)
	{
		if(h[i-1]>a[i])
		{
			ans++;
			ans%=998244353;
			dfs(h[i-1]-1-a[i],i-1);
		}
	}
	cout<<ans;
	return 0;
}
