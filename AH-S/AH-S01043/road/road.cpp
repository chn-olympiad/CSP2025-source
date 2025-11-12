#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long LL;
inline int read()
{
	re int x=0; re char c;
	while((c=getchar())<'0');
	do x=(x<<1)+(x<<3)+(c^48);
	while((c=getchar())>='0');
	return x;
}
const int N=1e4+5,M=1e6+6;
int n,m,k;
namespace Case1
{
	struct Pair
	{
		int x,y,w;
		void input() {x=read(),y=read(),w=read();}
		bool operator < (const Pair &x) const
		{
			return w<x.w;
		}
	}edge[M];
	int f[N];
	inline int find(int x)
	{
		if(x!=f[x]) f[x]=find(f[x]);
		return f[x];
	}
	inline void solve()
	{
		for(int i=1;i<=n;++i) f[i]=i;
		for(re int i=0;i<m;++i) edge[i].input();
		sort(edge,edge+m);
		int cnt=1; LL ans=0;
		for(re int i=0;i<m && cnt!=n;++i)
		{
			int fx=find(edge[i].x),fy=find(edge[i].y);
			if(fx!=fy) ++cnt,f[fx]=fy,ans+=edge[i].w;
		}
		cout<<ans;
	}
}
namespace Case2
{
	const int N=1003;
	struct Pair
	{
		int x,y,w;
		void input() {x=read(),y=read(),w=read();}
		bool operator < (const Pair &x) const
		{
			return w<x.w;
		}
	}edge[M+N*10];
	int f[N],a[N],g[N][N];
	inline int find(int x)
	{
		if(x!=f[x]) f[x]=find(f[x]);
		return f[x];
	}
	inline void solve()
	{
		for(int i=1;i<=n;++i) f[i]=i;
		for(re int i=0;i<m;++i) edge[i].input();
		memset(g,0x7f,sizeof g);
		for(re int i=0;i<k;++i)
		{
			const int c=read();
			for(re int j=1;j<=n;++j)
			{
				a[j]=read();
				for(re int k=1;k<j;++k)
					g[j][k]=min(g[j][k],a[j]+c+a[k]);
			}
		}
		int tot=m;
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<i;++j)
				edge[tot++]={i,j,g[i][j]};
		sort(edge,edge+tot);
		int cnt=1; LL ans=0;
		for(re int i=0;i<m+tot && cnt!=n;++i)
		{
			int fx=find(edge[i].x),fy=find(edge[i].y);
			if(fx!=fy) ++cnt,f[fx]=fy,ans+=edge[i].w;
		}
		cout<<ans;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(!k) Case1::solve();
	else Case2::solve();
	return 0;
}
//I am so weak.
