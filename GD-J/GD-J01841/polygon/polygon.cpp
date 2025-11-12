#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
const int mod=998244353;
int ans;
int n,a[N];
int vis[N];
int mx,s;
void dfs(int s,int mx,int p)
{
	if (s>mx*2)
	{
		ans++;
//		return;
	}
	for (int i=p;i<=n;i++)
	{
		if (vis[i]==0&&mx>=a[i])
		{
			vis[i]=1;
			dfs(s+a[i],mx,i);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]); 
	}
	for (int i=1;i<=n;i++)
	{
		s=0;
		mx=a[i];
		s+=a[i];
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(s,mx,1);
	}
	printf("%lld\n",ans%mod);
	return 0;
}
