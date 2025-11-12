#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
int n,m,k,cnt;
ll ans;
const int N=1e4+10,M=1e6+10,K=15;
const ll Inf=1e16+10;
bool ok[K];
int c[K],fa[N];
struct Node
{
	int u,v,w;
}l[M],a[K][N],e[M+K*N],tmp[M+K*N];
bool cmp(Node a,Node b)
{
	return a.w<b.w;
}
int fnd(int x)
{
	return fa[x]==x?x:fa[x]=fnd(fa[x]);
}
void qsort(int x)
{
	int l1=1,l2=1,p=0;
	while(l1<=n&&l2<=cnt)
	{
		if(a[x][l1].w<tmp[l2].w) e[++p]=a[x][l1++];
		else e[++p]=tmp[l2++];
	}
	while(l1<=n) e[++p]=a[x][l1++];
	while(l2<=cnt) e[++p]=tmp[l2++];
	cnt=p;
	for(int i=1;i<=cnt;i++)
		tmp[i]=e[i];
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&l[i].u,&l[i].v,&l[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x);
			a[i][j]={n+i,j,x};
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	sort(l+1,l+m+1,cmp);
	ans=Inf;
	for(int s=0;s<1<<k;s++)
	{
		for(int i=1;i<=k;i++)
			ok[i]=s&(1<<i-1);
		ll res=0;
		int tot=0,num=n;
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		for(int i=1;i<=m;i++)
			e[i]=tmp[i]=l[i];
		cnt=m;
		for(int i=1;i<=k;i++)
			if(ok[i])
			{
				res+=c[i];
				num++;
				qsort(i);
			}
		if(res>=ans) continue;
		for(int i=1;i<=cnt;i++)
		{
			int tu=fnd(e[i].u),tv=fnd(e[i].v);
			if(tu!=tv)
			{
				fa[tu]=tv;
				tot++;
				res+=e[i].w;
				if(tot==num-1||res>=ans) break;
			}
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
