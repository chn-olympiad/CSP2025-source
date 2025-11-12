#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&-x)
#define endl '\n'

namespace satsujinki{
const int INF=1e18;
const int maxn=2e4+10;
const int Maxn=1e6+10;
int n,m,k;
struct Node{
	int u,v,w;
}edge[Maxn],edge2[maxn],edge3[Maxn];
int cnt,cnt2;
int c[12],a[12][maxn];
int fa[maxn],sz[maxn];

int find(int id)
{
	return fa[id]==id?id:fa[id]=find(fa[id]);
}

bool cmp(Node _a,Node _b)
{
	return _a.w<_b.w;
}

void MAIN()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int uu=find(edge[i].u),vv=find(edge[i].v);
		if(uu!=vv)
		{
			fa[vv]=uu;
			edge2[++cnt]=edge[i];
		}
	}
	int minn=INF;
	for(int l=0;l<(1<<k);l++)
	{
		for(int i=1;i<=cnt;i++)
		{
			edge3[i]=edge2[i];
		}
		cnt2=cnt;
		int sum=0;
		for(int i=1;i<=k;i++)
		{
			if((l>>(i-1))&1)
			{
				sum+=c[i];
				for(int j=1;j<=n;j++)
				{
					edge3[++cnt2]={i+n,j,a[i][j]};
				}
			}
		}
		sort(edge3+1,edge3+cnt2+1,cmp);
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
			sz[i]=1;
		}
		for(int i=1;i<=cnt2;i++)
		{
			int uu=find(edge3[i].u),vv=find(edge3[i].v);
			if(uu!=vv)
			{
				if(sz[uu]<sz[vv])
				{
					swap(uu,vv);
				}
				fa[vv]=uu;
				sz[uu]+=sz[vv];
				sum+=edge3[i].w;
			}
		}
		minn=min(minn,sum);
	}
	cout<<minn<<endl;
}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	satsujinki::MAIN();
//while(1);
	return 0;
}
/*
time:1.0 S
memory:512 MiB
real:50MB


*/
