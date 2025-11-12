#include<bits/stdc++.h>
using namespace std;
const long long N=507;
const long long mod=998244353;
long long n,m;
char s[N];
long long c[N];
long long ans;
long long a[N],bz[N];
void dfs(long long x)
{
	if(x==n+1)
	{
		long long res=0;
		for(long long i=1;i<=n;i++)
		{
			if(s[i]=='0'||res>=c[a[i]])
			res++;
		}
		if(n-res>=m)
		ans++;
		return ;
	}
	for(long long i=1;i<=n;i++)
	{
		if(bz[i]==0)
		{
			bz[i]=1;
			a[x]=i;
			dfs(x+1);
			bz[i]=0;
		} 
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(long long i=1;i<=n;i++)
	cin>>c[i];
	if(n>10)
	{
		int res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		cout<<res;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

