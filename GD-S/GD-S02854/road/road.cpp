#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w);
	for(int i=1,c,a;i<=k;i++)
	{
		scanf("%d",&c);
		for(int j=1;j<=n;j++) scanf("%d",&a),ans+=a;
	}
	printf("%lld",ans);
	return 0;
}
