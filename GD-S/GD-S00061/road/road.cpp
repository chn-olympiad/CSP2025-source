#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
typedef pair<int,int> PII;
struct node
{
	int x,y,w;
}L[M],L1[N*N];
bool cmp(node A,node B)
{
	return A.w<B.w;
}
int c[N],dep[N];
int d[N][N];
vector<PII>G[N],G1[N];
bool vis[N],v[11];
int q[11][N];
int sum,t;
int main()
{
	freopen("road2.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,w;i<=m;i++)
	{
		scanf("%d%d%d",&L[i].x,&L[i].y,&L[i].w);
	}
	sort(L+1,L+m+1,cmp);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++)
	{
		d[min(L[i].x,L[i].y)][max(L[i].x,L[i].y)]=L[i].w;
	}
	memset(vis,0,sizeof(vis));
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x=L[i].x,y=L[i].y,w=L[i].w;
		if(!(vis[x]&&vis[y]))
		{
			vis[x]=vis[y]=1;
			G[x].push_back({y,w});
			G[y].push_back({x,w});
			ans+=w;
			printf("%d %d %d\n",x,y,w);
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&q[i][j]);
		}
	}
	memset(v,0,sizeof(v));
	while(1)
	{
		int mx=0,id=0;
		for(int i=1;i<=k;i++)
		{
			if(!v[i])
			{
				int g=0;
				v[i]=1;
				t=i;
				for(int x=1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						L1[++g].x=x;
						L1[g].y=y;
						L1[g].w=min(q[i][x]+q[i][y],d[x][y]);
					}
				}
				memset(vis,0,sizeof(vis));
				sort(L1+1,L1+g+1,cmp);
				int ans1=0;
				for(int i=1;i<=g;i++)
				{
					int x=L1[i].x,y=L1[i].y,w=L1[i].w;
					if(!(vis[x]&&vis[y]))
					{
						vis[x]=vis[y]=1;
						ans1+=w;
					}
				}
				if(ans>ans1+c[i])
				{
					printf("%d %d %d\n",i,ans1,c[i]);
					ans=ans1+c[i];
					id=i;
				}
			}
		}
		if(!id)
		{
			break;
		}
		for(int i=1;i<=m;i++)
		{
			int x=L[i].x,y=L[i].y;
			L[i].w=min(L[i].w,q[t][x]+q[t][y]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
