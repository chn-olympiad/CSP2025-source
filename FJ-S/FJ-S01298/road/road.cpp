#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		ans+=w;
	}
	printf("%lld",ans);
	return 0;
}

