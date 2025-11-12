#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;//nd t cg
int n,m,k,fa[N],vis[N],ans=0;
int c[N],a[15][N];
int res=0;
struct node{
	int u,v,w,id;
}e[N];
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void unoinn(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		fa[x]=y;
	}
	return ;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
void kruscal()
{
	int cnt=0; 
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(cnt==n-1)
		{
			return ;
		}
		if(u!=v)
		{
			unoinn(u,v);
			ans+=e[i].w;
			cnt++;
		}
	}
	return ;
}
void kruscal2(int x)
{
	int cnt=0; 
	int min1=0;
	sort(e+1,e+m+res+1,cmp);
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n+x;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m+res;i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(cnt==n-1)
		{
			return ;
		}
		if(u!=v)
		{
			unoinn(u,v);
			if(e[i].u>m&&vis[e[i].u]==false)
			{
				min1+=c[e[i].id];
				vis[e[i].u]=true;
			}
			else if(e[i].v>m&&vis[e[i].v]==false)
			{
				min1+=c[e[i].id];
				vis[e[i].v]=true;
			}
			else
			{
				min1+=e[i].w;
				cnt++;
			}
		}
	}
	ans=min(min1,ans);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	if(k==0)
	{
		kruscal();
		cout<<ans<<endl;
	}
	else
	{
		bool f0=true;
		kruscal();
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			if(c[i]!=0)
			{
				f0=false;
			}
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				if(a[i][j]!=0)
				{
					f0=false;
				}
			}
			if(f0==true)
			{
				cout<<0<<endl;
				return 0;
			}
		}
		for(int i=1;i<=k;i++)
		{
			res++;
			for(int j=1;j<=n;j++)
			{
				e[res+m+j].u=res+m;
				e[res+m+j].v=j;
				e[res+m+j].w=a[i][j];
				e[res+m+j].id=i;
			}
			kruscal2(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
