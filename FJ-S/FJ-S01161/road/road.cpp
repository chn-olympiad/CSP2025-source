#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
long long ans=0;
int fa[10004],fe[11];
bool paid[11];
struct E
{
	int u,v,w;
}e[2000006],et[200005];
inline bool cmp(E a,E b){return a.w<b.w;}
int fi(int p)
{
	if(fa[p]==p)return p;
	return fa[p]=fi(fa[p]);
}
inline bool ch()
{
	int f=fi(1);
	for(int i=2;i<=n;i++)
	{
		if(f!=fi(i))return 0;
	}
	return 1;
}
long long K()
{
	for(int i=1;i<=m;i++)
	{
		if(ch())return ans;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(fi(u)==fi(v))continue;
		ans+=w;
		fa[fi(u)]=fi(v);
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&fe[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&et[i*n+j].u,&et[i*n+j].v,&et[i*n+j].w);
		}
	}
	sort(e+1,e+1+m,cmp);
	printf("%lld",K());
	return 0;
}
