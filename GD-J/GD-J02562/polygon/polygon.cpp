#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,o[10000001],sum[10000001],len;
void dfs(ll u,ll sum,ll big)
{
	if(o[big]*2<sum && big>=3)
	{
		len++;
	}
	if(big==n) return;
	for(int i=big+1;i<=n;i++)
	{
		dfs(u,sum+o[i],i);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&o[i]);
	sort(o+1,o+1+n);
	for(int i=1;i<=n;i++) dfs(i,o[i],i);
	printf("%lld",len);
	return 0;
}

