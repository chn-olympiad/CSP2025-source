#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define maxn 10005
#define maxm 1000005
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c && c<='9'))
	{
		if(c=='-')
		  f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int n,m,k,cnt,num;
bool vis[15];//check way
int c[11];
//int dis[11][maxn+10][maxn+10];
int f[maxn+10];
long long sum,ans;

int find(int x)
{
	if(f[x]==x)
	  return x;
	return f[x]=find(f[x]);
}

struct Edge
{
	int u,v,w,id;//id ->check
	bool operator <(const Edge x1)const
	{
		return w>x1.w;
	}
}edge[maxm+10*maxn];

/*
struct Tree
{
	int l,r,val,id;
}tree[(maxn+10)<<2];

void pushup(int i)
{
	if(tree[i<<1].val<tree[i<<1|1].val)
	{
	  tree[i].val=tree[i<<1].val;
	  tree[i].id=tree[i<<1].id;
	}
	else
	{
	  tree[i].val=tree[i<<1|1].val;
	  tree[i].id=tree[i<<1|1].id;
	}
}

void build(int i,int l,int r)
{
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)
	{
		tree[i].val=dis[0][1][tree[i].l];
		tree[i].id=tree[i].l;
		return ;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	pushup(i);
	return ;
}

int query(int i,int l,int r)
{
	return tree[1].id;
}

void updatec(int i,int x,int w)
{
	if(tree[i].l==tree[i].r)
	{
		if(tree[i].l==x)
			tree[i].val=w;
		return ;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(x<=mid)
	  update(i<<1,x,w);
	else
	  update(i<<1|1,x,w);
	pushup(i);
	return ;
}
void updatem(int i,int x,int w)
{
	if(tree[i].l==tree[i].r)
	{
		if(tree[i].l==x)
			tree[i].val=min(tree[i].val,w);
		return ;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(x<=mid)
	  update(i<<1,x,w);
	else
	  update(i<<1|1,x,w);
	pushup(i);
	return ;
}*/

long long min(long long x,long long y)
{
	return x<y?x:y;
}

void work()
{
	for(int i=1;i<=n+k;i++)
	   f[i]=i;
	priority_queue<Edge> q;
	for(int i=1;i<=cnt;i++)
	   if(vis[edge[i].id])
	     q.push(edge[i]);
	long long t=1,s=0;
	while(!q.empty())
	{
		int x=q.top().u;
		int y=q.top().v;
		if(find(x)!=find(y))
		{
			f[f[x]]=f[y];
		    s+=q.top().w;
		    if(x<=n && y<=n)
		      ++t;
  		    if(t==n)
              break;
		}
		q.pop();
	}
	ans=min(ans,s+sum);
}

void dfs(int nw)
{
	if(nw>k)
	{
		work();
		return ;
	}
	vis[nw]=true;
	sum+=c[nw];
	dfs(nw+1);
	vis[nw]=false;
	sum-=c[nw];
	dfs(nw+1);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)
	   edge[++cnt].u=read(),edge[cnt].v=read(),edge[cnt].w=read(),edge[cnt].id=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
	       edge[++cnt].u=n+i,edge[cnt].v=j,edge[cnt].w=read(),edge[cnt].id=i;
	}
	sort(edge+1,edge+cnt+1);
    /*memset(dis[0],0x3f,sizeof(dis[0]));
    for(int i=1;i<=m;i++)
    {
		int u=read();
		int v=read();
		int w=read();
		dis[0][v][u]=dis[0][u][v]=min(dis[0][u][v],w);
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			int w=read();
			dis[i][n+i][j]=dis[i][j][n+i]=min(dis[i][j][n+i],w);
		}
	}*/
	sum=0,ans=0x7fffffff;
	vis[0]=true;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
