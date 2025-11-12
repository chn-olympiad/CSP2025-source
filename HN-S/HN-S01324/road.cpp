#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=1e6+5,M=1e4+15;
class Node
{
public:
	int x,y,w;
	bool operator<(const Node& tmp)const
	{
		return w<tmp.w;
	}
}e[N],p[N];
int n,tot,m,k,val[M],w[15][M];
ll ans=1e18;
bool vis[N];

namespace bcj
{
int fa[N];
inline void init(int n){for(int i=1;i<=n;i++)fa[i]=i;return ;}
int Find(int x){if(fa[x]==x)return x;return fa[x]=Find(fa[x]);}
inline void un(int x,int y){fa[y]=x;return ;}
}

inline void kruskal(ll num)
{
	tot=0;
	int edg=0;
	for(int i=1;i<=k;i++)
		if(vis[i]==true)
		{
			edg++;
			for(int j=1;j<=n;j++)
				p[++tot]={n+i,j,w[i][j]};
		}
	bcj::init(n+k);
	sort(p+1,p+tot+1);
	int i=1,j=1,cnt=0;
	while(cnt+1<n+edg)
	{
		Node now=e[i];
		if(j<=tot&&p[j].w<e[i].w)
			now=p[j++];
		else
			++i;
		int X=bcj::Find(now.x),Y=bcj::Find(now.y);
		if(X==Y)
			continue;
		bcj::un(X,Y);
		num+=now.w;
		cnt++;
		if(num>=ans)
			return ;
	}
	ans=num;
	return ;
}

void dfs(int cur,ll num)
{
	if(num>=ans)
		return ;
	if(cur==k+1)
	{
		kruskal(num);
		return ;
	}
	dfs(cur+1,num);
	vis[cur]=true;
	dfs(cur+1,num+val[cur]);
	vis[cur]=false;
	return ;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
			cin>>w[i][j];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
