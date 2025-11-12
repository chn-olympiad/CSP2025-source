#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
namespace GY2025YY
{
	const int N=1003;
	int n,m,k,mn[N],fa[N],g[N][N];
	bool f[N];
	//
	inline int find(int x)
	{
		if (fa[x]!=x) fa[x]=find(fa[x]);
		return fa[x];
	}
	//
	struct Node
	{
		int u,v,w;
		bool operator<(const Node tmp) const
		{
			return this->w>tmp.w;
		}
	};
	priority_queue<Node> q;
	int main()
	{
		freopen("road.in", "r", stdin);
		freopen("road.out","w",stdout);
		scanf("%d%d%d",&n,&m,&k);
		if (k==0)
		{
			for (int i=1;i<=n;++i) fa[i]=i;
			int u,v,w,cnt=n;
			while (m--)
			{
				scanf("%d%d%d",&u,&v,&w);
				q.push( {u,v,w} );
			}
			long long ans=0;
			while (cnt>1)
			{
				int fu=find(q.top().u),fv=find(q.top().v);
				if (fu!=fv) --cnt,ans+=q.top().w,f[fv]=fu;
				q.pop();
			}
			printf("%lld",ans);
		}
		else
		{
			memset(g,0x7f,sizeof(g));
			int u,v,w;
			while (m--)
			{
				scanf("%d%d%d",&u,&v,&w);
				g[u][v]=g[v][u]=min(g[u][v],w);
			}
			while (k--)
			{
				scanf("%*d");
				for (int i=1;i<=n;++i)
					scanf("%d",mn+i);
				for (int i=1;i<n;++i)
				{
					for (int j=i+1;j<=n;++j)
						g[i][j]=g[j][i]=min(g[i][j],mn[i]+mn[j]);
				}
			}
			memset(mn,0x7f,sizeof(mn));
			long long ans=0;mn[1]=0;
			for (int i=1;i<=n;++i)
			{
				k=0;
				for (int j=1;j<=n;++j)
					if (!f[j] && mn[j]<mn[k]) k=j;
				f[k]=true,ans+=mn[k];
				for (int j=1;j<=n;++j)
					if (!f[j] && mn[j]>g[k][j]) mn[j]=g[k][j];
			}
			printf("%lld",ans);
		}
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

