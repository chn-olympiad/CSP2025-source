#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],ans;
void dfs(int x,int k,int sum,int maxn)
{
	if (k<1)
		return ;
	for (int i=x;i<=n;i++)
	{
		if (sum+a[i]>2*max(a[i],maxn))
			ans=(ans+1)%MOD;	
		dfs(i+1,k-1,sum+a[i],max(a[i],maxn));
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,n,0,0);
	printf("%d",ans%MOD);
	return 0;
}
