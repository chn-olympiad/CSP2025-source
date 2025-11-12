#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int M=1000000,K=20,N=30000;
const long long inf=10000000000000;
struct edge
{
	int u,v,w;
}
edge1[M],edge2[K][N],edge3[K][N],edge4[N];
int n,k,c[K],f[N],g[N],siz[K];
long long ans;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void init()
{
	int i;
	for (i=1;i<=n+k;i++) f[i]=i;
	for (i=1;i<=n+k;i++) g[i]=0;
}
int getf(int x)
{
	if (f[x]!=x) f[x]=getf(f[x]);
	return f[x];
}
void merge(int x,int y)
{
	int a,b;
	a=x;
	b=y;
	if (g[a]>g[b]) swap(a,b);
	f[a]=b;
	if (g[a]==g[b]) g[b]++;
}
void dfs(int x,long long y)
{
	long long sum;
	int i,j,l,a,b;
	if (x>k)
	{
		sum=y;
		for (i=0;i<siz[x-1];i++) sum+=edge3[x-1][i].w;
		ans=min(ans,sum);
		return;
	}
	siz[x]=siz[x-1];
	for (i=0;i<siz[x];i++) edge3[x][i]=edge3[x-1][i];
	dfs(x+1,y);
	for (i=j=l=0;i<siz[x-1]||j<=n;) if (i<siz[x-1]&&(j>n||cmp(edge3[x-1][i],edge2[x][j]))) edge4[l++]=edge3[x-1][i++];
	else edge4[l++]=edge2[x][j++];
	init();
	siz[x]=0;
	for (i=0;i<l;i++)
	{
		a=getf(edge4[i].u);
		b=getf(edge4[i].v);
		if (a==b) continue;
		merge(a,b);
		edge3[x][siz[x]++]=edge4[i];
	}
	dfs(x+1,y+c[x]);
}
int read()
{
	char x;
	int i;
	do x=getchar();
	while (x<'0'||x>'9');
	for (i=0;x>='0'&&x<='9';x=getchar()) i=i*10+x-'0';
	return i;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,i,j,x,y;
	n=read();
	m=read();
	k=read();
	for (i=0;i<m;i++)
	{
		edge1[i].u=read();
		edge1[i].v=read();
		edge1[i].w=read();
	}
	for (i=1;i<=k;i++)
	{
		c[i]=read();
		for (j=1;j<=n;j++)
		{
			edge2[i][j].u=n+i;
			edge2[i][j].v=j;
			edge2[i][j].w=read();
		}
	}
	sort(edge1,edge1+m,cmp);
	for (i=1;i<=k;i++) sort(edge2[i]+1,edge2[i]+n+1,cmp);
	init();
	for (i=0;i<m;i++)
	{
		x=getf(edge1[i].u);
		y=getf(edge1[i].v);
		if (x==y) continue;
		merge(x,y);
		edge3[0][siz[0]++]=edge1[i];
	}
	ans=inf;
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
