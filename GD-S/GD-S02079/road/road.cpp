#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int n,m,k,w_cnt,x,y,z,w_fa[10005],w_size[10005],c[15],a[15][10005],f[1005][1005],g[1005][1005];
long long w_temp,w_ans;
struct node{
	int u,v,w;
	bool operator<(const node &p)const
	{
		return w<p.w;
	}
}w_edge[1000005];
int w_find(int x)
{
	if(w_fa[x]==x)
		return x;
	else
		return w_fa[x]=w_find(w_fa[x]);
}
void w_Kruscal()
{
	z=0;
	for(int i=1;i<=n;i++)
	{
		w_size[i]=1;
		w_fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(z==n-1)
			break;
		x=w_find(w_edge[i].u);
		y=w_find(w_edge[i].v);
		if(x!=y)
		{
			z++;
			w_temp+=w_edge[i].w;
//			printf("%d+",w_edge[i].w);
			if(w_size[x]<w_size[y])
			{
				w_size[y]+=w_size[x];
				w_fa[x]=y;
			}
			else
			{
				w_size[x]+=w_size[y];
				w_fa[y]=x;
			}
		}
	}
//	printf("\n");
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			f[i][j]=f[j][i]=2e9;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		f[x][y]=f[y][x]=z;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&w_temp);
		if(w_temp)
		{
			c[++w_cnt]=w_temp;
			for(int j=1;j<=n;j++)
				scanf("%d",&a[w_cnt][j]);
		}
		else
		{
			w_cnt++;
			for(int j=1;j<=n;j++)
				scanf("%d",&a[w_cnt][j]);
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
					f[i][j]=f[j][i]=min(f[i][j],a[w_cnt][i]+a[w_cnt][j]);
			}
			w_cnt--;
		}
	}
//	printf("f[][]:\n");
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			printf("%d ",f[i][j]);
//		printf("\n");
//	}
	w_ans=1e13;
	for(int s=0;s<(1<<w_cnt);s++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				g[i][j]=g[j][i]=f[i][j];
		}
//		printf("s=%d,g[][]:\n",s);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//				printf("%d ",g[i][j]);
//			printf("\n");
//		}
		w_temp=0;
		for(int i=1;i<=w_cnt;i++)
		{
			if(s&(1<<(i-1)))
			{
				w_temp+=c[i];
				for(int l=1;l<=n;l++)
				{
					for(int j=l+1;j<=n;j++)
						g[l][j]=g[j][l]=min(g[l][j],a[i][l]+a[i][j]);
				}
			}
		}
		m=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
//			{
				w_edge[++m]={i,j,g[i][j]};
//				if(s==2)
//					printf("%d->%d %d\n",i,j,g[i][j]);
//			}
		}
		sort(w_edge+1,w_edge+1+m);
		w_Kruscal();
//		printf("%d:%lld\n",s,w_temp);
		w_ans=min(w_ans,w_temp);
	}
	printf("%lld",w_ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
