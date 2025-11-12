#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
void read(long long &x)
{
	x=0;
	long long f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=(c=='-'? -f:f),c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}
struct edge
{
	long long u,v,w;
}a[1100000],v[20][11000],tmp[40][200000];
bool operator <(edge x,edge y){return x.w<y.w;}
long long n,m,k,ans=0x3f3f3f3f3f3f3f3f;
long long c[15],siz[40];
long long fa[11000];
long long find(long long a)
{
	long long x=a;
	while(x!=fa[x]) x=fa[x];
	while(a!=fa[a])
	{
		long long u=a;
		a=fa[a];
		fa[u]=x;
	}
	return a;
}
void merge(long long f,long long s)
{
	f=find(f),s=find(s);
	if(f!=s) fa[s]=f;
}
void mege(edge res[],long long &rsiz,edge a[],long long asiz,edge b[],long long bsiz)
{
	long long pa=1,pb=1;
	while(pa<=asiz&&pb<=bsiz)
	{
		if(a[pa]<b[pb]) res[++rsiz]=a[pa],pa++;
		else res[++rsiz]=b[pb],pb++;
	}
	while(pa<=asiz) res[++rsiz]=a[pa],pa++;
	while(pb<=bsiz) res[++rsiz]=b[pb],pb++;
}
void getsort(long long id,long long s,long long l,long long r)
{
	siz[id]=0;
	if(l==r)
	{
		if(s&(1<<l-1))
		{
			siz[id]=n;
			for(int i=1;i<=n;i++) tmp[id][i]=v[l][i];
		}
		return;
	}
	long long mid=l+r>>1;
	getsort(2*id,s,l,mid);
	getsort(2*id+1,s,mid+1,r);
	mege(tmp[id],siz[id],tmp[2*id],siz[2*id],tmp[2*id+1],siz[2*id+1]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) read(a[i].u),read(a[i].v),read(a[i].w);
	sort(a+1,a+1+m);
	long long cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			merge(a[i].u,a[i].v);
			v[k+1][++cnt]=a[i];
		}
	}
	v[k+1][n]={0,0,0x3f3f3f3f3f3f3f3f};
	for(int i=1;i<=k;i++)
	{
		read(c[i]);
		for(int j=1;j<=n;j++)
		{
			long long a;
			read(a);
			v[i][j]={n+i,j,a};
		}
		sort(v[i]+1,v[i]+1+n);
	}
	for(int i=0;i<(1<<k);i++)
	{
		long long sum=0,rs=i|(1<<k),ct=0,mc=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=k+1;j++)
		{
			if(rs&(1<<j-1)) sum+=c[j],mc++;
		}
		mc=mc-1+n-1;
		getsort(1,rs,1,k+1);
		for(int j=1;j<=siz[1];j++)
		{
			edge e=tmp[1][j];
			if(find(e.u)!=find(e.v))
			{
				merge(e.u,e.v);
				ct++;
				sum+=e.w;
			}
			if(ct==mc) break;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
