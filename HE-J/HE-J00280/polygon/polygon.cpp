#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,p=998244353;
int a[N],ans,maxn=-10000,n,b[N];
void dfs(int k,int mx,int sum,int cnt)
{
	if (k==n+1)
	{
		if (cnt<3) return;
		if (sum>mx*2) ans=(ans+1)%p;
		else return;
		return;
	}
	b[cnt+1]=a[k];
	dfs(k+1,a[k],sum+a[k],cnt+1);
	b[cnt+1]=0;
	dfs(k+1,mx,sum,cnt);
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
