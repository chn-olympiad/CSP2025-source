//#include<iostream> 
//#include<cstdio>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//class Edge
//{
//	public:
//		int u,v,w;
//};
//
//int find(vector<int>&fa,int u)
//{
//	if(fa[u]!=u)
//	{
//		fa[u]=find(fa,fa[u]);
//	}
//	return fa[u];
//}
//
//long long solve(vector<Edge>&edge,vector<int>&fa,int n,int m)
//{
//	long long ans=0;
//	sort(edge.begin()+1,edge.begin()+1+m,[](Edge&a,Edge&b)
//	{
//		return a.w<b.w;
//	});
//	for(int i=1;i<=n;i++)
//	{
//		fa[i]=i;
//	}
//	int cnt=n;
//	for(int i=1;i<=m;i++)
//	{
//		if(find(fa,edge[i].u)!=find(fa,edge[i].v))
//		{
//			fa[find(fa,edge[i].u)]=find(fa,edge[i].v);
//			ans+=edge[i].w;
//			cnt--;
//		}
//	}
//	return ans;
//}
//
//int main()
//{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
//	int n,m,k;
//	scanf("%d%d%d",&n,&m,&k);
//	vector<Edge>edge(m+n*k+1);
//	for(int i=1;i<=m;i++)
//	{
//		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
//	}
//	vector<int>c(k+1);
//	vector<vector<int>>a(k+1,vector<int>(n+1));
//	for(int i=1;i<=k;i++)
//	{
//		scanf("%d",&c[i]);
//		for(int j=1;j<=n;j++)
//		{
//			scanf("%d",&a[i][j]);
//		}
//	}
//	vector<int>fa(n+k+1);
//	long long ans=1e18;
//	for(int i=0;i<(1<<k);i++)
//	{
//		int idx=m,cnt=n;
//		long long ww=0;
//		for(int j=0;j<k;j++)
//		{
//			if((i>>j)&1)
//			{
//				cnt++;
//				ww+=c[j+1];
//				for(int t=1;t<=n;t++)
//				{
//					idx++;
//					edge[idx].u=cnt,edge[idx].v=t,edge[idx].w=a[j+1][t];
//				}
//			}
//		}
//		ans=min(ans,solve(edge,fa,cnt,idx)+ww);
//	}
//	cout<<ans<<endl;
//	return 0;
//}

#include<iostream> 
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class Edge
{
	public:
		int u,v;
		long long w;
};

int find(vector<int>&fa,int u)
{
	if(fa[u]!=u)
	{
		fa[u]=find(fa,fa[u]);
	}
	return fa[u];
}

void dfs1(vector<vector<pair<int,long long>>>&g,vector<vector<int>>&tree,
		vector<long long>&w,int root,int fa)
{
	for(int i=0;i<g[root].size();i++)
	{
		if(g[root][i].first!=fa)
		{
			tree[root].emplace_back(g[root][i].first);
			dfs1(g,tree,w,g[root][i].first,root);
		}
		else
		{
			w[root]=g[root][i].second;
		}
	}
}

void dfs2(vector<vector<int>>&tree,vector<long long>&c,vector<vector<long long>>&a,
		  vector<long long>&w,vector<vector<long long>>&dp,int u,int n,int k)
{
	dp[u][0]=0;
	for(int i=0;i<(1<<k);i++)
	{
		dp[u][i]=0;
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				dp[u][i]+=a[j+1][u];
			}
		}
	}
	vector<long long>ndp(1<<k,1e18);
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		dfs2(tree,c,a,w,dp,v,n,k);
		for(int j=0;j<(1<<k);j++)
		{
			for(int t=0;t<(1<<k);t++)
			{
				if(j&t)
				{
					ndp[j|t]=min(ndp[j|t],dp[u][j]+dp[v][t]);
				}
				else
				{
					ndp[j|t]=min(ndp[j|t],dp[u][j]+dp[v][t]+w[v]);
				}
			}
		}
		for(int j=0;j<(1<<k);j++)
		{
			dp[u][j]=ndp[j];
			ndp[j]=1e18;
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<Edge>edge(m+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	vector<long long>c(k+1);
	vector<vector<long long>>a(k+1,vector<long long>(n+1));
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	vector<int>fa(n+1);
	sort(edge.begin()+1,edge.end(),[](Edge&a,Edge&b)
	{
		return a.w<b.w;
	});
	vector<vector<pair<int,long long>>>g(n+1);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(find(fa,edge[i].u)!=find(fa,edge[i].v))
		{
			fa[find(fa,edge[i].u)]=find(fa,edge[i].v);
			g[edge[i].u].emplace_back(edge[i].v,edge[i].w);
			g[edge[i].v].emplace_back(edge[i].u,edge[i].w);
		}
	}
	vector<long long>w(n+1);
	vector<vector<int>>tree(n+1);
	dfs1(g,tree,w,1,-1);
	vector<vector<long long>>dp(n+1,vector<long long>(1<<k,1e18));
	dfs2(tree,c,a,w,dp,1,n,k);
	long long mn=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		long long cnt=0;
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				cnt+=c[j+1];
			}
		}
		mn=min(mn,dp[1][i]+cnt);
	}
	cout<<mn<<endl;
	return 0;
}
