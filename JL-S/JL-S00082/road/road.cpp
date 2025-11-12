//[0,4]
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	int ans = 0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		ans+=w;
	}
	printf("%lld\n",ans);
}