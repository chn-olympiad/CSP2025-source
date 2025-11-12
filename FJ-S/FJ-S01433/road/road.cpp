#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
	int nextt;
}e[100005];
struct node2{
	int u,v,w;
}e2[300005];
int head[10005];
int n,m,k;
int cnt;
int cnt2;
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].v=y;
	e[cnt].w=z;
	e[cnt].nextt=head[x];
	head[x]=cnt;
}
void add2(int x,int y,int z)
{
	cnt2++;
	e2[cnt2].u=x;
	e2[cnt2].v=y;
	e2[cnt2].w=z;
}
bool cmp(const node2 &t1,const node2 &t2)
{
	return t1.w<t2.w;
}
int c[15];
int a[15][100005];
int fa[100005];
int findfa(int x)
{
	if(fa[x]!=x) return fa[x]=findfa(fa[x]);
	return x;
}
void solve()
{
	for(int i=1;i<=k;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
			{
				x=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(x==j)continue;
			add2(x,j,a[i][j]);
		} 
	}
	sort(e2+1,e2+1+cnt2,cmp);
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt2;i++)
	{
		int x=e2[i].u;
		int y=e2[i].v;
		int xx=findfa(x);
		int yy=findfa(y);
		if(xx!=yy)
		{
			fa[xx]=yy;
			ans+=e2[i].w;
		}
	}
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add2(x,y,z);
	}
	bool flag=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(flag==0)
	{
		solve();
	}
	return 0;
		
} 
/*
4 4 0
1 4 6
2 3 7
4 3 5
4 3 4

*/
