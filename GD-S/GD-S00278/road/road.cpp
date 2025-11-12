#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,f[N],h[N],cnt,sp[15][N],city[N];
long long minn=1e18+5;
struct road
{
	int u,v,w;
} a[N],b[N],c[N];
bool cmp(road x,road y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(register int i=1;i<=m;++i)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(register int i=1;i<=k;++i)
	{
		scanf("%d",&city[i]);
		for(register int j=1;j<=n;++j) scanf("%d",&sp[i][j]);
	}
	sort(a+1,a+m+1,cmp);
	for(register int i=1;i<=n;++i) f[i]=i,h[i]=0;
	for(register int i=1;i<=m;++i)
	{
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu==fv) continue;
		if(h[fu]>h[fv]) f[fv]=fu;
		else
		{
			f[fu]=fv;
			if(h[fu]==h[fv]) h[fv]++;
		}
		cnt++,b[cnt]=a[i];
	}
	for(register int i=0;i<(1<<k);++i)
	{
		int len=cnt;
		long long ans=0;
		for(register int j=1;j<=cnt;++j) c[j]=b[j];
		for(register int j=1;j<=k;++j)
			if((i&(1<<(j-1)))!=0)
			{
				for(register int o=1;o<=n;++o)
					len++,c[len].u=o,c[len].v=n+j,c[len].w=sp[j][o];
				ans+=city[j];
			}
		sort(c+1,c+len+1,cmp);
		for(register int j=1;j<=n+k;++j) f[j]=j,h[j]=0;
		for(register int j=1;j<=len;++j)
		{
			int fu=find(c[j].u),fv=find(c[j].v);
			if(fu==fv) continue;
			if(h[fu]>h[fv]) f[fv]=fu;
			else
			{
				f[fu]=fv;
				if(h[fu]==h[fv]) h[fv]++;
			}
			ans+=c[j].w;
		}
		minn=min(minn,ans);
	}
	printf("%lld",minn);
	return 0;
 } 
