#include<bits/stdc++.h>
using namespace std;
const int N=1e4+51;
struct Date{
	int x,y;long long len;
};Date d[N*100],f[1030][N],a[15][N];
int n,m,K,co[N],sl[1030];
bool bj[1030];long long g[1030],c[15];
bool cmp(Date x,Date y)
{
	if(x.len<y.len)
	return 1;
	return 0;
}
int find(int x)
{
	if(co[x]==x)
	return x;
	return co[x]=find(co[x]);
}
int read()
{
	int s=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s=(s<<1)+(s<<3)+ch-'0';ch=getchar();
	}
	return s;
}
void get(int mb,int S,int k)
{
	int i=1,j=1,x,y;
	for(i=1;i<=n+K;i++)
	co[i]=i;
	i=j=1;bj[mb]=1;
	while(i<=sl[S]&&j<=n)
	{
		if(f[S][i].len<a[k][j].len)
		{
			x=find(f[S][i].x);y=find(f[S][i].y);
			if(x!=y)
			{
				co[x]=y;g[mb]+=f[S][i].len;f[mb][++sl[mb]]=f[S][i];
			}
			i++;
		}
		else
		{
			x=find(a[k][j].x);y=find(a[k][j].y);
			if(x!=y)
			{
				co[x]=y;g[mb]+=a[k][j].len;f[mb][++sl[mb]]=a[k][j];
			}
			j++;
		}
	}
	if(i<=sl[S])
	{
		x=find(f[S][i].x);y=find(f[S][i].y);
		if(x!=y)
		{
			co[x]=y;g[mb]+=f[S][i].len;f[mb][++sl[mb]]=f[S][i];
		}
		i++;
	}
	if(j<=n)
	{
		x=find(a[k][j].x);y=find(a[k][j].y);
		if(x!=y)
		{
			co[x]=y;g[mb]+=a[k][j].len;f[mb][++sl[mb]]=a[k][j];
		}
		j++;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int S,i,j,x,y,ss;
	n=read();m=read();K=read();
	for(i=1;i<=m;i++)
	d[i].x=read(),d[i].y=read(),d[i].len=read();
	for(i=0;i<K;i++)
	{
		c[i]=read();
		for(j=1;j<=n;j++)
		{
			a[i][j].len=read();
			a[i][j].x=n+i+1;a[i][j].y=j;
		}
	}
	sort(d+1,d+m+1,cmp);
	for(i=0;i<K;i++)
	sort(a[i]+1,a[i]+n+1,cmp);
	for(i=1;i<=n;i++)
	co[i]=i;
	ss=0;
	for(i=1;i<=m;i++)
	{
		x=find(d[i].x);y=find(d[i].y);
		if(x!=y)
		{
			g[0]+=d[i].len;co[x]=y;f[0][++ss]=d[i];
		}
	}
	sl[0]=ss;
	S=1<<K;
	for(i=0;i<S;i++)
	{
		for(j=0;j<K;j++)
		{
			if((i&(1<<j))==0&&bj[i|(1<<j)]==0)
			get(i|(1<<j),i,j);
		}
	}
	long long ans=1e18;
	for(i=0;i<S;i++)
	{
		for(j=0;j<K;j++)
		{
			if((i&(1<<j))!=0)
			g[i]+=c[j];
		}
		ans=min(ans,g[i]);
	}
	printf("%lld",ans);
	return 0;
}
