//48
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int a[5005],c[15],vis[15];
int n,anss;
int C(int y)
{
	int aa = 1;
	for(int i=n;i>=n-y+1;i--)
		aa = (aa*i)%mod;
	int bb = 1;
	for(int i=1;i<=y;i++)
		bb = (bb*i)%mod;
	return aa/bb;
}
void dfs(int dep,int mdep)
{
	if(dep==mdep+1)
	{
		bool flag = 0;
		for(int i=2;i<=mdep;i++)
		{
			if(c[i]>c[i-1]) flag = 1;
		}
		if(flag) return;
		int maxx = 0,sum = 0;
		for(int i=1;i<=mdep;i++)
		{
			maxx = max(maxx,a[c[i]]);
			sum += a[c[i]];
		}
		if(sum>2*maxx) anss++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		//if(i>c[dep-1]) continue;
		c[dep] = i;
		vis[i] = 1;
		dfs(dep+1,mdep);
		vis[i] = 0;

	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int maxx = 0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxx = max(maxx,a[i]);
	}
	if(n<=3)
	{
		if(n<=2) puts("0");
		else
		{
			int cmax = max(max(a[1],a[2]),a[3]);
			if((a[1]+a[2]+a[3])>(cmax*2)) puts("1");
			else puts("0");
		}
	}
	else if(maxx==1)
	{
		int ans = 0;
		for(int i=3;i<=n;i++)
		{
			ans = (ans+C(i))%mod;
		}
		printf("%lld\n",ans);
	}
	else if(n<=10)
	{
		for(int i=3;i<=n;i++)
		{
			memset(c,0,sizeof(c));
			memset(vis,0,sizeof(vis));
			dfs(1,i);
		}
		printf("%lld\n",anss%mod);
	}
	else
	{
		int ans = 0;
		for(int i=3;i<=n;i++)
		{
			ans = (ans+C(i))%mod;
		}
		printf("%lld\n",ans);
	}
}