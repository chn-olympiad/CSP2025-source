#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;

int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x;
}
const int maxn=1e4+20;
bool vis[maxn];
bool rebuild[29];
int a[29][maxn];
int c[maxn];
int dis[maxn];
//int f[maxn];
struct node
{
	int v,w;
};
vector<node>G[maxn];
//int find(int x)
//{
//	if(f[x]==x)return x;
//	return f[x]=find(f[x]);
//}
//bool merge(int a,int b)
//{
//	a=find(a);b=find(b);
//	if(a==b)return false;
//	f[a]=b;
//	return true;
//}	
ll ans=1e18;
int n,m,k;
struct NODE
{
	int u,dis;
	bool operator<(const NODE &you)const
	{
		return dis>you.dis;
	}
};
void prim(ll &now,int num)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<NODE>q;
	q.push({1,0});
	dis[1]=0;
	int siz=0;
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		now+=dis[u];
		siz++;
		if(now>=ans||siz==n+num)return;
		vis[u]=true;
		if(u>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[u-n][i]<dis[i])
				{
					dis[i]=a[u-n][i];
					q.push({i,dis[i]});
				}
			}
		}
		else
		{
			for(int i=1;i<=k;i++)
			{
				if(rebuild[i])
				{
					if(a[i][u]<dis[i+n])
					{
						dis[i+n]=a[i][u];
						q.push({i+n,dis[i+n]});
					}
				}
			}
			for(auto it:G[u])
			{
				int v=it.v,w=it.w;
				if(w<dis[v])
				{
					dis[v]=w;
					q.push({v,dis[v]});
				}
			}
		}
	} 
//	printf("[%lld]\n",now);
}
//int res=0;
void dfs(int now)
{
	if(now==k+1)
	{
	//	res++;
	//	printf("[%d]\n",res);
		int num=0;
		ll tot=0;
		for(int i=1;i<=k;i++)
		{
			if(rebuild[i])
			{
				num++;
				tot+=c[i];
			}
		}
		prim(tot,num);
		
	//	putchar('\n');
		ans=min(ans,tot);
		return;
	}
	dfs(now+1);
	rebuild[now]=1;
	dfs(now+1);
	rebuild[now]=0;
}	
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cout<<log2(1e6)
	n=read();m=read();k=read();
	while(m--)
	{
		int u,v,w;
		u=read();v=read();w=read();
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}

