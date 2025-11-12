#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=5e5+5;
int n,ans;
int a[N];
void dfs(int step,int sum,int cnt)
{
	if(cnt>=3&&sum>a[step]*2) ans++,ans%=MOD;
	for(int i=step+1;i<=n;i++)
	{
		dfs(i,sum+a[i],cnt+1);
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
