#include<bits/stdc++.h>
struct E{int u,v,w;}e[2000005];
int f[10005],c[15],a[10005][15];
int _g(int x){return x==f[x]?x:f[x]=_g(f[x]);}
int main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=0;i<k;++i)
	{
		scanf("%d",c+i);
		int p=-1;
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a[j][i]);
			if(a[j][i]==0&&c[i]==0)p=j;
		}
		for(int j=0;j<n;++j)
			e[m].u=p,e[m].v=j,e[m++].w=a[j][i];
	}
	int ct=0,r=0;
	for(int i=0;i<n;++i)
		f[i]=i;
	std::sort(e,e+m,[](E a,E b){return a.w<b.w;});
	for(int i=0;i<m;++i)
	{
		int u=_g(e[i].u),v=_g(e[i].v);
		if(u==v)continue;
			f[u]=v;r+=e[i].w;
		if(++ct==n-1)
			break;
	}
	printf("%d",r);
	return 0;
}//rp++

