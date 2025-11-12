#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k;
struct edge{
	int u,v;
	long long w;
};
long long c[15];
long long a[15][N];
vector<edge>g;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int fa[N];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve1()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	long long ans=0;
	sort(g.begin(),g.end(),cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(g[i].u),fy=find(g[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=g[i].w;
	}
	cout<<ans<<endl;
	return;
}
bool check()
{
	for(int i=1;i<=k;i++)
	{
		if(c[i]!=0) return false;
	}
	return true;
}
void solveA()
{
	long long ans=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g.push_back({n+i,j,a[i][j]});
		}
	}
	for(int i=1;i<=n+11;i++) fa[i]=i;
	sort(g.begin(),g.end(),cmp);
	for(int i=1;i<g.size();i++)
	{
		int fx=find(g[i].u),fy=find(g[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=g[i].w;
	}
	cout<<ans<<endl;
}
int ord[N];
long long res=LLONG_MAX;
long long work()
{
	long long ans=0;
	vector<edge>e;
	for(int i=1;i<=m;i++) e.push_back({g[i].u,g[i].v,g[i].w});
	for(int i=1;i<=k;i++)
	{
		if(ord[i]==0) continue;
		ans+=c[i];
		for(int j=1;j<=n;j++)
		{
			e.push_back({i+n,j,a[i][j]});
		}
	}
	//for(int i=0;i<e.size();i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
	//cout<<endl;
	for(int i=1;i<=n+11;i++) fa[i]=i;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=e[i].w;
	}
	return ans;
}
void dfs(int x)
{
	if(x>k)
	{
		long long ans=work();
		//for(int i=1;i<=k;i++) cout<<ord[i]<<" ";
			//cout<<ans<<endl;	
		res=min(res,ans);
		return;
	}
	
	dfs(x+1);
	ord[x]=1;
	dfs(x+1);
	ord[x]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	g.push_back({0,0,0});
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		long long w;
		cin>>w;
		g.push_back({u,v,w});
	 }
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	} 
	if(k==0) solve1();
	else if(check()) solveA();
	else
	{
		dfs(1);
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
