#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,k;
struct road
{
	long long u=0,v=0,w=0;
	operator < (const road &x/*, const _Tp& __y*/) const { return x.w < w; }
};
long long a[15][1010],c[15],su[1010],fa[1010],sum=0;
bool b[1010][1010];
road mon[1000050];
bool cmp(road x,road y)
{
	return x.w>y.w;
}
void cango(int o,int p)
{
	//cout<<o<<' '<<p<<' '<<su[o]<<' '<<su[p]<<' ';
	if (o==p)
	{
		su[o]--;
		b[o][p]=1,b[p][o]=1;
		/*mon[(o-1)*n+p].w=0;
		mon[(p-1)*n+o].w=0;*/ 
		//cout<<endl;
		return;
	}
	if (b[o][p]==1||b[p][o]==1||su[o]<2||su[p]<2)
	{
		//cout<<endl;
		return;
	}
	long long zx1=-1,zx2=-1;
	for (int i=1;i<=n;i++)if (i!=p&&i!=o&&(b[p][i]==0||b[i][p]==0)&&su[i]>1)zx1=fa[i];
	for (int i=1;i<=n;i++)if (i!=p&&i!=o&&(b[o][i]==0||b[i][o]==0)&&su[i]>1)zx2=fa[i];
	//cout<<zx1<<' '<<zx2<<endl;
	if (zx1==zx2&&zx1>0&&zx2>0)
	{
		su[o]--,su[p]--;
		b[o][p]=1,b[p][o]=1;
		/*mon[(o-1)*n+p].w=0;
		mon[(p-1)*n+o].w=0;*/ 
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*for (int i=1;i<=1001;i++)for (int j=1;j<=1001;j++)mon[{i,j}]=9187201950435737471;
	const long long lmax=9187201950435737471;*/
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++){mon[(i-1)*n+j]={i,j,91872019504357374};fa[i]=1;}
	for (int i=1;i<=m;i++)
	{
		long long g,h,j;
		scanf("%lld%lld%lld",&g,&h,&j);
		mon[(g-1)*n+h].w=min(mon[(g-1)*n+h].w,j);
		mon[(h-1)*n+g].w=min(mon[(h-1)*n+g].w,j);
	}
	for (int i=1;i<=n;i++)su[i]=n;
	for (int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	for (int q=1;q<=k;q++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=n;j++)
			{
				long long cost=a[q][i]+a[q][j]+c[q];
				mon[(i-1)*n+j].w=min(mon[(i-1)*n+j].w,cost);
				mon[(j-1)*n+i].w=min(mon[(j-1)*n+i].w,cost);
			}
		}
	}
	/*for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)cout<<mon[(i-1)*n+j].w<<' ';
		cout<<endl;
	}*/ 
	int l=n*n;
	sort(mon+1,mon+l+1,cmp);
	//cout<<endl;for (int i=1;i<=l;i++)cout<<mon[i].u<<' '<<mon[i].v<<' '<<mon[i].w<<endl;cout<<endl;
	for (int i=1;i<=l;i++)
	{
		road now=mon[i];
		cango(now.u,now.v);
		//if (cango(now.u,now.v))b[now.u][now.v]=1,mon[i].w=0;
	}
	for (int i=1;i<=l;i++)if (!b[mon[i].u][mon[i].v])/*cout<<mon[i].u<<' '<<mon[i].v<<' '<<mon[i].w<<endl,*/sum+=mon[i].w;
	printf("%lld",sum/2);
	return 0;
}
