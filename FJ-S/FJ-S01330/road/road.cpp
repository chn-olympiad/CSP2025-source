#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=2000005;
int head[M],Next[M],ver[M],edge[M],tot;
void add(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
/*struct node{
	int x,y,z;
}a[M];*/
int n,m,k,v[N],a[N][N],b[13][N],c[15];
int d[2][N];
void spfa(int X)
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	queue<int> q;
	q.push(X);
	v[X]=1;
	d[X][X]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=Next[i])
		{
			int y=ver[i],z=edge[i];
			if(v[y]==1)
				continue;
			if(d[X][y]>d[X][x]+z)
			{
				d[X][y]=d[X][x]+z;
				q.push(y);
				v[y]=1;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
//		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		add(x,y,z);
		add(y,x,z);
	}
	int fl=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]!=0)
			fl=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
			if(b[i][j]!=0)
				fl=0;
		}
	}
	if(fl && k!=0)
	{
		puts("0");
		return 0;
	}
	spfa(1);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,d[1][i]);
	printf("%d",ans);
	return 0;
}