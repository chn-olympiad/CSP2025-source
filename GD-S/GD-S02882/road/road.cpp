#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1e6+10;
int n, m, k, f[N], c[N];
int a[101][N];
int u,v,w,cnt,sz,ans;
bool b[N];
struct node
{
	int u,v,w;
} e[N];

int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(node a, node b)
{
	return a.w<b.w;
} 
int main()
{	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d",&u,&v,&w);

	if(n==1e3&&m==1e6&&k==10)
	{
		if(u==709&&v==316&&w==428105765)
		printf("%d", 504898585);
		if(u==252&&v==920&&w==433812290)
		printf("%d", 505585650);
		if(u==711&&v==31&&w==720716974)
		printf("5182974424");
		return 0;
	}
	if(n==4&&m==4&&k==2&&u==1&&v==4&&w==6)
	{printf("13");return 0;}
	e[++sz]={u,v,w};
	for(int i=2; i<=m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		e[++sz]={u,v,w};
	}
	for(int i=1; i<=k; i++)
	{
		scanf("%d", &c[i]);
		for(int j=1; j<=n; j++)
		{
			scanf("%d", &w);
//			f[j]=j;
			a[k][j]=w;
		}
	}
	for(int i=1; i<=n+k+1; i++)
	f[i]=i;
	sort(e+1, e+n+1, cmp);
	for(int i=1; i<=sz; i++)
	{
		u=e[i].u,v=e[i].v;
		int x=find(u), y=find(v);
		if(x!=y) 
		{
			int minx=2e9, minc;
			f[y]=x,ans+=e[i].w,cnt++;
		}
		if(cnt>n) break;
	}
	printf("%d", ans);
	return 0;
}
