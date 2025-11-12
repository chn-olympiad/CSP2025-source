#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,Ans=1e9;
struct node{int u,v,w;};
vector<node> side,Side;
bool cmp(node x,node y)
{return x.w<y.w;}
bool vis[15];
int fa[10015];
int bui[15];
int W[15][10005];
int get(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
void kr(int all,int ans)
{
//	cout<<all<<"\n";
	Side.clear();
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int cnt=0;
	for(node k:side)Side.push_back(k);
	sort(Side.begin(),Side.end(),cmp);
//	for(node k:Side)cout<<k.u<<" "<<k.v<<" "<<k.w<<"\n";
	for(node k:Side)
	{
		int x=get(k.u);
		int y=get(k.v);
		if(x==y)continue;
		fa[y]=x;
		ans+=k.w;
		cnt++;
		if(cnt==all)break;
	}
//	cout<<ans<<"\n";
	Ans=min(ans,Ans);
}
void dfs(int id)
{
	if(id==k+1)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=k;i++)
		{
			if(vis[i]==1)
			{
				cnt++;sum+=bui[i];
				for(int j=1;j<=n;j++)
					side.push_back((node){i+m,j,W[i][j]});
			}
		}
		kr(cnt+n-1,sum);
		for(int i=1;i<=k;i++)
		{
			if(vis[i]==1)
			{
				for(int j=1;j<=n;j++)
					side.pop_back();
			}
		}
		return ;
	}
	vis[id]=0;
	dfs(id+1);
	vis[id]=1;
	dfs(id+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		side.push_back((node){u,v,w});
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		cin>>bui[i];
		if(bui[i]!=0)flag=0;
		for(int j=1;j<=n;j++)
		{
			cin>>W[i][j];
			if(W[i][j]!=0)flag=0;
		}
	}
	if(flag){cout<<0;return 0;}
	dfs(1);
	cout<<Ans;
	return 0;
}
