#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[100005],fsum[100005];
long long ans;
struct pp{
	int u,v,w; 
}b[1000005];
bool cmp(pp x,pp y)
{
	return x.w < y.w;
}
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	if(k != 0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&b[i].u,&b[i].v,&b[i].w);
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i,fsum[i]=1;
	for(int i=1;i<=m;i++)
	{
		int u=b[i].u,v=b[i].v,fu=find(u),fv=find(v);
		if(fu != fv)
		{
			ans+=b[i].w;
			fa[fv]=fu;
			fsum[fu]+=fsum[fv];
			if(fsum[fu] == n)
			{
				printf("%lld",ans);
				return 0;
			}
		}
	}
	return 0;
}
