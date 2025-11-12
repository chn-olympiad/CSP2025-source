#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,MOD=998244353;
int n,a[N];
int ans;

void dfs(int now,int k,int csum,int maxcl)
{
	if(k>=3)
	{
		if(csum>2*maxcl)
		{
			ans++;
			ans%=MOD;
		}
	}
	if(now>n)
		return;
	for(int i=now;i<=n;i++)
	{
		dfs(i+1,k,csum,maxcl);
		dfs(i+1,k+1,csum+a[i],max(maxcl,a[i]));
	}
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
