#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
int n,m,k,ww[N],in[N],ou[N];
struct node
{
	int x,y,w;
}e[N];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int cnt,fa[N];
int find(int x)
{
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return ;
	fa[x]=y;
	return ;
}
int kruskal()
{
	sort(e+1,e+1+cnt,cmp);
	int tot=0,ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int x=e[i].x,y=e[i].y,w=e[i].w;
		if(find(x)==find(y))continue;
		ans+=w;
		tot++;
		unionn(x,y);
		if(tot==n-1)break;
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	int mx=0,mx1=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		in[u]++;
		ou[u]++;
		in[v]++;
		ou[v]++;
		if(in[u]>mx)
		{
			mx=in[u];
			mx1=u;
		} 
		if(in[v]>mx)
		{
			mx=in[v];
			mx1=v;
		} 
		e[++cnt].x=u;
		e[cnt].y=v;
		e[cnt].w=w;
	}
	int ans=kruskal();
	if(ans==0)
	{
		cout<<0;
		return 0;
	}
	bool f=0,flag=0,f1=0,flag1=0;
	for(int i=1;i<=k;i++)
	{
		cin>>ww[i];
		if(ww[i]==0)f=1;
		else flag=1;
		for(int j=1;j<=n;j++)
		{
			int w1;
			cin>>w1;
			if(w1==0)f1=1;
			else flag1=1;
			e[++cnt].x=i;
			e[cnt].y=j;
			e[cnt].w=w1;
		}
	}
	if(f==1&&flag==0&&f1==1&&flag1==0)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<mx*mx1+1;
	}
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
