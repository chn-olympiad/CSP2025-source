#include<cstdio>
#include<algorithm>
#define re register
#define ll long long int 
using namespace std;
const ll Inf=1e18;
const int N=1e4,M=1e6,Kk=10,_N=1e3;
struct edge
{
	int u,v;
	ll w;
}b[(M<<1)+5];
struct node
{
	int id;
	ll vl;
}a[Kk+5][N+5];
struct rng
{
	int l,r;
}zz[Kk+5];
ll c[Kk+5];
int fa[N+5];
int d[Kk+5+5];
ll ds[_N+5][_N+5],ds2[_N+5][_N+5];
ll ans=Inf;
int n,m,K;
bool cmpb(edge x,edge y)
{
	return x.w<y.w;
}
bool cmpa(node x,node y)
{
	return x.vl<y.vl;
}
int fnd(int x)
{
	return (fa[x]==x)?x:fa[x]=fnd(fa[x]);
}
ll gt()
{
	m=0;
	ll s=0;
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)
		{
			ds[i][j]=ds2[i][j];
		}
	}
	for(re int i=1;i<=d[0];i++)
	{
		s+=c[d[i]];
		for(re int j=1;j<=n;j++)
		{
			for(re int k=j+1;k<=n;k++)
			{
				ds[j][k]=ds[k][j]=min(ds[j][k],a[d[i]][j].vl+a[d[i]][k].vl);
			}
		}
	}
	for(re int i=1;i<=n;i++)
	{
		for(re int j=i+1;j<=n;j++)
		{
			if(ds[i][j]!=Inf)
			{
				b[++m]={i,j,ds[i][j]};
			}
		}
	}
//	printf("%d\n",m);
	sort(b+1,b+1+m,cmpb);
	int sm=0;
	for(re int i=1;i<=m;i++)
	{
		int t1=fnd(b[i].u),t2=fnd(b[i].v);
		if(t1!=t2)
		{
			fa[t1]=t2,sm++,s+=b[i].w;
			if(sm==(n-1))
			{
				break;
			}
		}
	}
	for(re int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	if(sm==(n-1))
	{
		return s;
	}
	else
	{
		return Inf;
	}
}
void dfs(int x)
{
//	printf("%d\n",x);
	if(x>K)
	{
//		printf("Yes");
		ans=min(ans,gt());
	}
	else
	{
		d[++d[0]]=x;
		dfs(x+1);
		d[0]--;
		dfs(x+1);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(re int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&b[i].u,&b[i].v,&b[i].w);
	}
	for(re int i=1;i<=K;i++)
	{
		scanf("%lld",&c[i]);
		for(re int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j].vl);
//			a[i][j].id=j;
		}
//		sort(a[i]+1,a[i]+1+n,cmpa);
	}
	if(n<=5e2)
	{
		for(re int i=1;i<=n;i++)
		{
			for(re int j=i+1;j<=n;j++)
			{
				ds2[i][j]=ds2[j][i]=Inf;
			}
		}
		for(re int i=1;i<=m;i++)
		{
			ds2[b[i].u][b[i].v]=ds2[b[i].v][b[i].u]=min(ds2[b[i].u][b[i].v],b[i].w);
		}
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	sort(b+1,b+1+m,cmpb);
	for(re int i=1;i<=K;i++)
	{
		zz[i]={1,2};
		for(re int j=1;j<=n;j++)
		{
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+1+n,cmpa);
	}
	int s=0,nw=1;
	ans=0;
	while(s<(n-1))
	{
		int s1=0;
		ll s2=Inf;
		for(re int i=1;i<=K;i++)
		{
			while((fnd(a[i][zz[i].l].id)==fnd(a[i][zz[i].r].id))&&(zz[i].l<n))
			{
				if(zz[i].r==n)
				{
					zz[i].l++;
					zz[i].r=zz[i].l+1;
				}
				else
				{
					zz[i].r++;
				}
			}
			if((zz[i].l<n)&&((a[i][zz[i].l].vl+a[i][zz[i].r].vl)<s2))
			{
				s1=i,s2=a[s1][zz[s1].l].vl+a[s1][zz[s1].r].vl;
			}
		}
		s2+=c[s1];
		while((fnd(b[nw].u)==fnd(b[nw].v))&&(nw<=m))
		{
			nw++;
		}
		if((s2<b[nw].w)||(nw>m))
		{
			int t1=fnd(a[s1][zz[s1].l].id),t2=fnd(a[s1][zz[s1].r].id);
//			if(t1!=t2)
//			{
				fa[t1]=t2,s++,ans+=s2,c[s1]=0;
				if(zz[s1].r==n)
				{
					zz[s1].l++;
					zz[s1].r=zz[s1].l+1;
				}
				else
				{
					zz[s1].r++;
				}
//			}
		}
		else
		{
			int t1=fnd(b[nw].u),t2=fnd(b[nw].v);
//			if(t1!=t2)
//			{
				fa[t1]=t2,s++,ans+=b[nw].w;
				nw++;
//			}
		}
	}
	printf("%lld",ans);
	return 0;
}
