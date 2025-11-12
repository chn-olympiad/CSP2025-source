#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,b[505],c[505],num=0,ans=0;
bool ok=1,d[505];
char a[505];
void dfs(int x)
{
	if (x<=n)
	{
		for (int i=1;i<=n;++i)
		if (!d[i])
		{
			c[x]=i;
			d[i]=1;
			dfs(x+1);
			d[i]=0;
		}
	}
	else
	{
		int cnt=0;
		for (int i=1;i<=n;++i)
		if (a[i]=='0' || cnt>=b[c[i]])
		++cnt;
		if (n-cnt>=m)
		ans=(ans+1)%mod;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(a+1);
	for (int i=1;i<=n;++i)
	cin>>b[i];
	if (m==n)
	{
		for (int i=1;i<=n;++i)
		if (a[i]=='0' || b[i]==0)
		ok=0;
		if (ok)
		{
			ans=1;
			for (int i=1;i<=n;++i)
			ans=(long long)ans*i%mod;
		}
	}
	else
	dfs(1);
	cout<<ans;
	return 0;
}
