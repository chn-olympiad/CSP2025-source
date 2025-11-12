#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,K;
int fa[10010];
struct edge
{
	int u,v;ll w;
};
edge e[1000010],g[1030][10110],f[20210];
ll c[15],s[15][10010];
ll ans=1e18;
inline bool cmp1(edge x,edge y){return x.w<y.w;}
inline int Find(int k)
{
	if(fa[k]==k) return k;
	return fa[k]=Find(fa[k]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(register int i=1;i<=m;i++) scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	for(register int i=1;i<=K;i++)
	{
		scanf("%lld",&c[i]);
		for(register int j=1;j<=n;j++) scanf("%lld",&s[i][j]);
	}
	for(register int j=0;j<(1<<K);j++)
	{
		int cnt=0;ll sum=0;
		if(!j)
		{
			sort(e+1,e+m+1,cmp1);
			for(register int i=1;i<=n;i++) fa[i]=i;
			for(register int i=1;i<=m;i++)
			{
				int fx=Find(e[i].u),fy=Find(e[i].v);
				if(fx==fy) continue;
				cnt++,g[0][cnt]=e[i],fa[fx]=fy,sum+=e[i].w;
				if(cnt==n-1) break;
			}
			ans=min(ans,sum);
			continue;
		}
		int pos=n+1,ppc=0;
		for(register int i=K;i>=1;i--) if(j&(1<<(i-1))){pos=i;break;}
		for(register int i=1;i<=K;i++) if(j&(1<<(i-1))) ppc++,sum+=c[i];
		int ss=(j^(1<<(pos-1))),mm=0;
		for(register int i=1;i<=n+ppc-2;i++) f[i]=g[ss][i],mm++;
		for(register int i=1;i<=n;i++) mm++,f[mm].u=n+pos,f[mm].v=i,f[mm].w=s[pos][i];
		sort(f+1,f+mm+1,cmp1);
		for(register int i=1;i<=n+K;i++) fa[i]=i;
		for(register int i=1;i<=mm;i++)
		{
			int fx=Find(f[i].u),fy=Find(f[i].v);
			if(fx==fy) continue;
			cnt++,g[j][cnt]=f[i],fa[fx]=fy,sum+=f[i].w;
			if(cnt==n+ppc-1) break;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
//虽然比赛前一天熬夜看无机杀手不是正确的行为，但是你不得不承认无机杀手很好看。 
//不过现在真的红温了，就这个状态真得保龄了。 
