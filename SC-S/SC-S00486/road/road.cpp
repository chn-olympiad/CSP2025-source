#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5000010;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,t;
int tot,sum,cnt;
int head[N],k=0;
int a[20][50010];
int fa[N],dis[N],id[N];
struct node
{
	int next,to,w;
}edge[N];
void add(int u,int v,int w)
{
	edge[++k].next=head[u];
	edge[k].to=v;
	edge[k].w=w;
	head[u]=k;
}
bool cmp(node a1,node a2)
{
	return a1.w<a2.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void kruskal()
{
	sort(edge+1,edge+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		int u=edge[i].next,v=edge[i].to,w=edge[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			cnt++;
			sum+=w;
			fa[fv]=fu;
			if(t!=0)
			{
				if(u>n) cnt--;
				else if(v>n) cnt--;
			}
		}
		if(cnt==n-1) break;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();t=read();
	for(int i=1;i<=n+t;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		u=read();v=read();w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=t;i++)
	{
		a[i][0]=read();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	if(t==0)
	{
		kruskal();
		cout<<sum<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=n;j++)
			{
				add(j,n+i,a[i][j]);
				add(n+i,j,a[i][j]);
			}
		}
		kruskal();
		cout<<sum<<endl;
	}
	return 0;
}
//Bocchi the Rock!
