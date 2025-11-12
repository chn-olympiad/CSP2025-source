#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,a[12][N],fa[N],ans;
bool sit[12];
vector<tuple<int,int,int> > E,e,edge;

int find(int x){return fa[x]=fa[x]==x?x:find(fa[x]);}

void dfs(int x)
{
	if(x>k)
	{
		e=edge;
		int res=0;
		for(int i=1;i<=k;i++)
		{
//			cout<<sit[i]<<' ';
			if(sit[i])
			{
				res+=a[i][0];
				for(int j=1;j<=n;j++) e.push_back(make_tuple(a[i][j],n+i,j));
			}
		}
		if(res>=ans) return;
//		cout<<endl;
		sort(e.begin(),e.end());
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(auto u:e)
		{
			int x=get<1>(u),y=get<2>(u),z=get<0>(u);
			if(find(x)!=find(y)) fa[find(x)]=find(y),res+=z;
			if(res>=ans) return;
		}
//		cout<<res<<endl;
		ans=min(res,ans);
		return;
	}
	dfs(x+1);
	sit[x]=true;
	dfs(x+1);
	sit[x]=false;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y,z;i<=m;E.push_back(make_tuple(z,x,y)),i++) cin>>x>>y>>z;
	sort(E.begin(),E.end());
	for(auto u:E)
	{
		int x=get<1>(u),y=get<2>(u),z=get<0>(u);
		if(find(x)!=find(y)) edge.push_back(make_tuple(z,x,y)),fa[find(x)]=find(y),ans+=z;
	}
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++) cin>>a[i][j];
	dfs(1);
	cout<<ans;
	return 0;
}
