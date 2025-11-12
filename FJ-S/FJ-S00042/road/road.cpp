#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[10005],c[15],d[15][10005],ans,lg[10005]={-1},fa[10005][20],deep[10005],s[10005];
pair<int,pair<int,int>>a[2000005];
vector<pair<int,int>>b[10005];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void join(int x,int y)
{
	f[find(x)]=find(y);
}
void scs(int c)
{
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].second.first)!=find(a[i].second.second))
		{
			if(c==1)
			{
				b[a[i].second.first].push_back({a[i].second.second,a[i].first});
				b[a[i].second.second].push_back({a[i].second.first,a[i].first});
			}
			ans+=a[i].first;
			join(a[i].second.first,a[i].second.second);
		}
	}
}
void dfs(int x,int ff)
{
	deep[x]=deep[ff]+1;
	fa[x][0]=ff;
	for(auto p:b[x])
	{
		if(p.first!=ff)
		{
			s[p.first]=s[x]+p.second;
			dfs(p.first,x);
		}
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	while(deep[x]>deep[y])
	{
		x=fa[x][lg[deep[x]-deep[y]]];
	}
	if(x==y)return x;
	for(int i=15;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}
void pd(int k)
{
	pair<int,pair<int,int>>t[10005];int cnt=0,vis[10005]={0},tt=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(vis[i])
			{
				if(!vis[j]&&d[k][j]<s[i]+s[j]-2*s[lca(i,j)])
				{
					vis[j]=1;
					t[++cnt]={d[k][j],{n+k,j}};
				}
			}
			else if(vis[j])
			{
				if(!vis[i]&&d[k][i]<s[i]+s[j]-2*s[lca(i,j)])
				{
					vis[i]=1;
					t[++cnt]={d[k][i],{n+k,i}};
				}
			}
			else
			{
				if(tt)
				{
					if(c[k]+d[k][i]+d[k][j]<s[i]+s[j]-2*s[lca(i,j)])
					{
						vis[i]=1;
						vis[j]=1;
						t[++cnt]={d[k][j],{n+k,j}};
						t[++cnt]={d[k][i],{n+k,i}};
					}
				}
				else
				{
					if(d[k][i]+d[k][j]<s[i]+s[j]-2*s[lca(i,j)])
					{
						tt=0;
						vis[i]=1;
						vis[j]=1;
						t[++cnt]={d[k][j],{n+k,j}};
						t[++cnt]={d[k][i],{n+k,i}};
					}
				}
			}
		}
	}
	if(cnt>=2)
	{
		for(int i=1;i<=cnt;i++)
		{
			a[m+i]=t[i];
		}
		m+=cnt;
		ans+=c[k];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		lg[i]=lg[i/2]+1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		a[i]={w,{u,v}};
	}
	sort(a+1,a+m+1);
	scs(1);
	ans=0;
	dfs(1,0);
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
		}
		pd(i);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(a+1,a+m+1);
	scs(2);
	cout<<ans;
	return 0;
}
