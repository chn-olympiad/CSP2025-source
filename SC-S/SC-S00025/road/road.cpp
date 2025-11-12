#include<bits/stdc++.h>
using namespace std;
void read(int &n)
{
	n=0;
	char c=getchar();
	while('0'>c or c>'9')c=getchar();
	while('0'<=c and c<='9')
	{
		n=n*10+c-'0';
		c=getchar();
	}
}
const int X=15,N=10015,M=1e6+1e5+5;
struct node
{
	int u,v,w;
}bi[M],bi2[M];//第一次跑是1e6，其他是11e4，都不会超
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int xf[X],bq[X][N],fa[N],h[N];
bool vis[M];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool merge(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)return 0;
	if(h[a]<h[b])swap(a,b);
	fa[b]=a;
	if(h[a]==h[b])
	{
		h[a]++;
	}
	return 1;
}
int cnt=0;
long long kruskal(int gs,int zs)
{
//	printf("开始选\n边集大小：%d，总共大小:%d\n",zs,gs);
	sort(bi+1,bi+zs+1,cmp);
//	printf("----------------------------------------边集:\n");
//	for(int i=1;i<=zs;i++)
//	{
//		printf("%d->%d:%d\n",bi[i].u,bi[i].v,bi[i].w);
//	}
	for(int i=1;i<=gs;i++)	
	{
		fa[i]=i;
		h[i]=0;
	}
	long long qz=0;
	for(int i=1;i<=zs;i++)
	{
		vis[i]=0;
		if(merge(bi[i].u,bi[i].v))
		{
			//printf("选择：%d->%d(%d)\n",bi[i].u,bi[i].v,bi[i].w);
			qz+=bi[i].w;
			vis[i]=1;
		}
	}
	return qz;
}
long long ans=9e18;
bool xz[X];
int n,m,k;
void dfs(int step)
{
//	printf("边集:\n");
//	for(int i=1;i<=cnt;i++)
//	{
//		printf("%d->%d:%d\n",bi[i].u,bi[i].v,bi[i].w);
//	}
	if(step==k+1)
	{
		long long xa=0;
		int xcnt=cnt,ycnt=n;
		for(int i=1;i<=cnt;i++)
		{
			bi[i].u=bi2[i].u;
			bi[i].v=bi2[i].v;
			bi[i].w=bi2[i].w;
		}
//		printf("开始：\n");
//		printf("边集:\n");
//		for(int i=1;i<=cnt;i++)
//		{
//			printf("%d->%d:%d\n",bi[i].u,bi[i].v,bi[i].w);
//		}
		for(int i=1;i<=k;i++)
		{
			if(xz[i])
			{
				xa+=xf[i];
				++ycnt;
				for(int j=1;j<=n;j++)
				{
//					printf("加边(%d,%d,%d):位置在%d\n",i+n,j,bq[i][j],xcnt+1);
					bi[++xcnt].u=ycnt;
					bi[xcnt].v=j;
					bi[xcnt].w=bq[i][j];
//					printf("其实实际边权为%d\n",bi[xcnt].w);
				}
			}
		}
//		printf("村庄修复情况：\n");
//		for(int i=1;i<=k;i++)
//		{
//			if(xz[i])
//			{
//				printf("%d,",i);
//			}
//		}
//		printf("已修复\n，边集:\n");
//		for(int i=1;i<=xcnt;i++)
//		{
//			printf("%d->%d:%d\n",bi[i].u,bi[i].v,bi[i].w);
//		}
		long long x=kruskal(ycnt,xcnt)+xa;
		ans=min(ans,x);
//		printf("已修复\n，边集:\n");
//		for(int i=1;i<=xcnt;i++)
//		{
//			printf("%d->%d:%d\n",bi[i].u,bi[i].v,bi[i].w);
//		}
//		printf("所以现在的最小生成树为%lld\n",x-xa);
		return;
	}
	xz[step]=0;
	dfs(step+1);
	xz[step]=1;
	dfs(step+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;i++)
	{
		read(bi[i].u);
		read(bi[i].v);
		read(bi[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		read(xf[i]);
		for(int j=1;j<=n;j++)
		{
			read(bq[i][j]);
		}
	}
	if(k<=5)
	{
		kruskal(n,m);
		for(int i=1;i<=m;i++)
		{
			if(vis[i])
			{
				bi2[++cnt].u=bi[i].u;
				bi2[cnt].v=bi[i].v;
				bi2[cnt].w=bi[i].w;
			}
		}
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}//K大，但是我们认为每个乡村都必须选就能完成性质A
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bi[++m].u=i+n;
			bi[m].v=j;
			bi[m].w=bq[i][j];
		}
	}
	printf("%lld\n",kruskal(n+k,m));
	return 0;
}
/*
k<=5:暴力枚举每个乡镇修不修复，然后就会得到一个TLE
不过也许能过n=1e3?
并非可以
如果还是像之前一样，暴力建边，就会被一个修复代价极大但是修复后收益很高的乡镇卡掉
K太小了，枚举应该是要的，但是枚举之后看一看每条边能否被替代？
先做最小生成树。
把每个乡村暴力塞进去做最小生成树就是特性A，可以得一共算上暴力的48分
暴力塞入太超模了，手动枚举塞入，X可以多拿8分X
有一个小小的优化：每次选择的边一定是生成树那些边和乡村边的并集，可以少10的常数
1e5 log 1e5=2e6*32=64e6，CCF老年机应该也能跑动，一共暴力喜提72分，太爽了
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 2 4
0 1 3 0 4

*/