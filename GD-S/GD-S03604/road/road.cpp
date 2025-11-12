#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000,M=200000,K=100;
struct node{int x,y,v;}a[M+K*N];
int fa[N+K];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int vid[K];//第vid[i]个乡村是否改造过 
int chang[K];
bool cmp(node a,node b)
{
	return a.v<b.v;
}
node b[M];
int vis[M]; 
int bc[K][N];
int l[N];
int to[N],nxt[N],val[N],head[N];
int cst=1;
void add(int x,int y,int v)
{
	to[cst]=y;
	nxt[cst]=head[y];
	val[cst]=v;
	head[x]=cst++;
}
int lx[10][1000];
signed main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","W",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].v;
		b[i].x=a[i].x;
		b[i].y=a[i].y;
		b[i].v=a[i].v;
		cnt++;
		add(a[i].x,a[i].y,a[i].v);
		add(a[i].y,a[i].x,a[i].v);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>chang[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			lx[i][j]=w;
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i; 
	sort(a+1,a+1+cnt,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			ans+=a[i].v;
			vis[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
