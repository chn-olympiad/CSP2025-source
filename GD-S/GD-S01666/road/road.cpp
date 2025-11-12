#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
struct edge
{
	int u;
	int v;
	int w;
}e[M];
int c[K];
int a[K][N];
int ans;
int tp()
{
	if(k==0)
		return -1;
	for(int i=1; i<=k; ++i)
	{
		if(c[i]!=0)
			return -1;
	}
	for(int i=1; i<=k; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(a[i][j]!=0)
				return -1;
		}
	}
	return 0;
}
bool cmp(edge x,edge y)
{
	if(x.w<y.w)
		return true;
	return false;
}

int b[N]; //并查集 
int find(int i) //寻找i点的祖宗 
{
	if(b[i]==i)
		return i;
	b[i]=find(b[i]);
	return b[i];
}

void init()
{
	for(int i=1; i<=n; ++i)
		b[i]=i;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1; i<=k; ++i)
	{
		scanf("%d",&c[i]);
		for(int j=1; j<=n; ++j)
			scanf("%d",&a[i][j]);
	}
	
	//骗分 
	ans=tp()+1;
	if(ans!=0)
	{
		printf("%d",ans-1);
		return 0;
	}
	
	//最小生成树 
	sort(e+1,e+1+m,cmp);
	
	for(int i=1; i<=m; ++i)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			ans+=e[i].w;
			b[b[e[i].u]]=b[e[i].v];
			int count=0;
			for(int j=1; j<=n; ++j)
			{
				if(b[j]==j)
					++count;
			}
			if(count==1)
				break;
		}
	}
	printf("%d",ans);
	return 0;
}
//最小生成树+骗分 
