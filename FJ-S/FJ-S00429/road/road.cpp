#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
const int N=1e4+15,M=(1<<10)+5,L=2e6+5,D=15;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n,m,K,idx,fa[M][N],siz[M][N],Fa[N],c[D];
vector<int> p[D];
long long res[M];
struct node{int u,v,w,o;}e[L];
int find(int o,int x){return fa[o][x]==x?x:fa[o][x]=find(o,fa[o][x]);}
bool merge(int o,int x,int y)
{
	x=find(o,x);y=find(o,y);
	if(x==y) return 0;
	if(siz[o][x]>siz[o][y]) swap(x,y);
	fa[o][x]=y;siz[o][y]+=siz[o][x];
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();K=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	idx=m;
	for(int i=1;i<=K;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
			idx++,e[idx].u=i+n,e[idx].v=j,e[idx].w=read(),e[idx].o=i;
	}
	sort(e+1,e+idx+1,[&](node x,node y)
	{
		return x.w<y.w;
	});
	for(int i=0;i<1<<K;i++)
		for(int j=1;j<=n+K;j++) fa[i][j]=j,siz[i][j]=1;
	for(int i=1;i<=K;i++)
		for(int j=1;j<1<<K;j++)
			if((j>>(i-1))&1) p[i].emplace_back(j);
	for(int i=1;i<=idx;i++)
		if(e[i].o)
		{
			if(merge(1<<(e[i].o-1),e[i].u,e[i].v)) res[1<<(e[i].o-1)]+=e[i].w;
			else continue;
			for(auto j:p[e[i].o])
				if(j!=1<<(e[i].o-1))
					if(merge(j,e[i].u,e[i].v)) res[j]+=e[i].w;
		}
		else
		{
			if(merge(0,e[i].u,e[i].v)) res[0]+=e[i].w;
			else continue;
			for(int j=1;j<1<<K;j++)
				if(merge(j,e[i].u,e[i].v)) res[j]+=e[i].w;
		}
	long long ans=INF;
	for(int i=0;i<1<<K;i++)
	{
		bool flg=1;
		for(int j=2;j<=n;j++)
			if(find(i,j)!=find(i,1)){flg=0;break;}
		if(!flg) continue;
		long long sum=res[i];
		for(int j=1;j<=K;j++)
			if((i>>(j-1))&1) sum+=c[j];
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
