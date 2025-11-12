#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define rep1(i,l,r) for(int i=l;i<=r;++i)
#define rep2(i,l,r) for(int i=l;i>=r;--i)
#define rep3(i,h,x,ne) for(int i=h[x];~i;i=ne[i])
#define rep4(x,v) for(auto x:v)
const int N=1e4+10;
const int M=2e6+10;
const int inf=0x3f3f3f3f3f3f3f3f;
using namespace std;
int n,m,k,c[11],a[11][N],fa[N],idx;
struct Graph
{
	int u,v;
	int w;
}G[M];
vector<Graph> v,p[11],g;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(Graph a,Graph b){return a.w<b.w;}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int kruskal(int cnt,bool type)
{
	rep1(i,1,n+k) fa[i]=i;
	int sum=0;
	rep1(i,1,cnt)
	{
		int pa=find(G[i].u),pb=find(G[i].v);
		if(pa==pb) continue;
		if(!type) v.push_back({G[i].u,G[i].v,G[i].w});
		fa[pa]=pb;
		sum+=G[i].w;
	}
	return sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	rep1(i,1,m)
	{
		G[i].u=read();
		G[i].v=read();
		G[i].w=read();
	}
	sort(G+1,G+m+1,cmp);
	int ans=kruskal(m,0);
	bool res=1;
	rep1(i,0,k-1)
	{
		c[i]=read();
		if(c[i]) res=0;
		rep1(j,1,n) 
		{
			a[i][j]=read();
			p[i].push_back({n+i+1,j,a[i][j]});
		}
		sort(p[i].begin(),p[i].end(),cmp);
	}
	int be=1;
	if(res) be=(1<<k)-1;
	rep1(s,be,(1<<k)-1)
	{
		int tot=0,sum=0;
		rep4(x,v) G[++tot]=x;
		rep1(j,0,k-1)
		{
			if(s&(1<<j)) 
			{
				sum+=c[j];
				int p1=1,p2=0;
				rep1(q,1,tot+n)
				{
					if(p2<n&&(p1>tot||p[j][p2].w<G[p1].w))
					{
						g.push_back(p[j][p2]);
						++p2;
					}
					else
					{
						g.push_back(G[p1]);
						++p1;
					}
				}
				tot=0;
				rep4(x,g) G[++tot]=x;
				g.clear();
			}
		}
		int now=kruskal(tot,1)+sum;
		ans=min(ans,now);
	}
	cout<<ans<<"\n";
	return 0;
}

