#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,ans,head[N],fa[N],cnt,vis[N];
struct ATRI
{
	int to,nxt,d,from;
}e[M*3];
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].from=u;
	e[cnt].nxt=head[u];
	e[cnt].d=w;
	head[u]=cnt;
}
bool cmp(ATRI x,ATRI y)
{
	return x.d>y.d;
}
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x);y=find(y);
	fa[x]=y;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1,w;i<=k;i++)
	{
		scanf("%d",&w);
//		cout<<"A";
		for(int j=1,x;j<=n;j++)
		{
			scanf("%d",&x);
			if(i==j) continue;
			add(i,j,w+x);
			add(j,i,w+x);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	queue<int> q;
	q.push(e[1].from);
	vis[e[1].from]=1;
	ans+=e[1].d;
//	cout<<ans<<' ';
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].nxt)
		{
//			cout<<e[i].d<<' ';
			int v=e[i].to;
			int uu=find(u);
			int vv=find(v);
			if(uu==vv||vis[v])
			{
//				cout<<"A";
				continue;
			}
			else
			{
				if(!vis[v]) q.push(v);
				vis[v]=1;
				merge(v,u);
				ans+=e[i].d;
//				break;
//				cout<<u<<' '<<v<<' '<<ans<<'\n';
			}
//			cout<<ans<<' ';
		}
//		cout<<'\n';
	}
	cout<<ans;
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