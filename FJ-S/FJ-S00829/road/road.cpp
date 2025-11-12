#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=10020,M=2000010,INF=1e18;
int n,m,k,now1,now2,ans;
int f[N],sz[N],cost[15];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
struct Edge
{
	int x,y,w;
	bool operator <(const Edge &X)const
	{
		return w<X.w;
	}
}edge[M],ed[15][N],ed2[M],ed3[M],ed4[M];
bool chkA()
{
	for(int i=1;i<=k;i++)if(cost[i])return false;
	return true;
}
void init(int n)
{
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(sz[fx]<fy)f[fx]=fy;
	else f[fy]=fx;
}
int kruskal()
{
	int ans=0;
	for(int i=1;i<=now1;i++)
	{
		int x=edge[i].x,y=edge[i].y;
		if(find(x)==find(y))continue;
		ans+=edge[i].w,merge(x,y);
	}
	return ans;
}
void workA()
{
	init(n+k);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			edge[++now1]=ed[i][j];
	sort(edge+1,edge+now1+1);
	ans=kruskal();
}
void mg()
{
	int i=1,j=1,now3=0;
//	puts("mg");
//	for(int i=1;i<=now1;i++)printf("%d ",edge[i].w);puts("");
//	for(int i=1;i<=now2;i++)printf("%d ",ed2[i].w);puts("");
	while(i<=now1&&j<=now2)
	{
		if(edge[i]<ed2[j])ed4[++now3]=edge[i++];
		else ed4[++now3]=ed2[j++];
	}
	while(i<=now1)ed4[++now3]=edge[i++];
	while(j<=now2)ed4[++now3]=edge[j++];
	for(int i=1;i<=now3;i++)edge[i]=ed4[i];
	now1=now3;
//	for(int i=1;i<=now1;i++)printf("%d ",edge[i].w);
//	puts("");
}
void work()
{
	ans=INF;
	for(int ch=0;ch<(1<<k);ch++)
	{
		init(n+k);
		int res=0;now2=0,now1=m;
		for(int i=1;i<=m;i++)edge[i]=ed3[i];
		for(int i=1;i<=k;i++)
		{
			if((ch>>(i-1))&1)
			{
				res+=cost[i];
				for(int j=1;j<=n;j++)ed2[++now2]=ed[i][j];
			}
		}
		sort(ed2+1,ed2+now2+1);
		mg();
		res+=kruskal();
		ans=min(ans,res);
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)edge[i].x=read(),edge[i].y=read(),edge[i].w=read();
	for(int i=1;i<=k;i++)
	{
		cost[i]=read();
		for(int j=1;j<=n;j++)
		{
			ed[i][j].w=read(),ed[i][j].x=n+i,ed[i][j].y=j;
		}
		sort(ed[i]+1,ed[i]+n+1);
	}
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;i++)ed3[i]=edge[i];
	now1=m;
	if(chkA())workA();
	else work();
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
