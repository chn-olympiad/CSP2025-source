#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[21],dis[21][2100000];
struct bi{
	int x,y,d;
}a[4100000];
int len,f[2100000];
bool v[2100000];
long long ans=LONG_LONG_MAX;
int read()
{
	int num=0,k=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*k;
}
void add(int x,int y,int d)
{
	a[++len].x=x;
	a[len].y=y;
	a[len].d=d;
}
int find(int x)
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
bool cmp(bi x,bi y)
{
	return x.d<y.d;
}
void fun(int num,int xl)
{
	long long tot=xl;
	int kk=1;
	for(int i=1;i<=num;i++) f[i]=i;
	for(int i=1;i<=len;i++)
	{
		int x=a[i].x,y=a[i].y;
		if(v[x]==0||v[y]==0) continue;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			f[fy]=fx;
			tot+=a[i].d;
			if(tot>=ans)
			  return;
			kk++;
			if(kk==num)
			{
				ans=min(ans,tot);
				return;
			}
		}
	}
}
void dfs(int to,int num,int xl)
{
	if(to>k)
	{
		fun(num,xl);
		return;
	}
	dfs(to+1,num,xl);
	v[n+to]=1;
	dfs(to+1,num+1,xl+c[to]);
	v[n+to]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u0,v0,w0;
	for(int i=1;i<=m;i++)
	{
		u0=read();v0=read();w0=read();
		add(u0,v0,w0);
	}
	bool vv=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]) vv=1;
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=read();
		}
	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	int tot=1;
	if(!vv)
	{
		ans=0;
		for(int j=1;j<=k;j++)
		  for(int kk=1;kk<=n;kk++)
		    add(n+j,kk,dis[j][kk]);
		sort(a+1,a+len+1,cmp);
		for(int i=1;i<=len;i++)
		{
			int x=a[i].x,y=a[i].y;
			int fx=find(x),fy=find(y);
			if(fx!=fy)
			{
				f[fy]=fx;
				ans+=a[i].d;
				tot++;
				if(tot==n+k)
				{
					printf("%lld\n",ans);
					return 0;
				}
			}
		}
	}
	else
	{
		for(int j=1;j<=k;j++)
		  for(int kk=1;kk<=n;kk++)
		    add(n+j,kk,dis[j][kk]);
		sort(a+1,a+len+1,cmp);
		for(int i=1;i<=n;i++) v[i]=1;
		dfs(1,n,0);
		printf("%lld",ans);
	}
	return 0;
}