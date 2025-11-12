#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[51][51][5001],n,a[5001],ans;
set<int> g[5001];
void dfs (int u,int sum,int m,int k)
{
	if(sum>2*m&&k>=3&&u>n) 
	    ans=(ans+1)%mod;
	if(u>n) return ;
	if(u>n) return ;
	dfs(u+1,sum,m,k);
	dfs(u+1,sum+a[u],a[u],k+1); 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
