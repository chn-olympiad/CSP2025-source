#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 10010
#define M 1000010
#define K 11
int n,m,k,c[K],a[K][N];
long long ans=1000000000000000000ll;
struct node
{
	int u,v,w;
	friend bool operator<(node a,node b)
	{
		return a.w<b.w;
	}
};
vector<node> edges,tmp,edgec[K],las;
class myDSU
{
	public:
		int n,fa[N];
		void init(int _n)
		{
			n=_n;
			for(int i=1;i<=n;i++)
			 fa[i]=i;
		}
		int findfa(int x)
		{
			if(fa[x]==x)
			 return x;
			return fa[x]=findfa(fa[x]);
		}
		bool merge(int x,int y)
		{
			x=findfa(x);
			y=findfa(y);
			if(x!=y)
			{
				fa[y]=x;
				return true;
			}
			return false;
		}
}dsu;
void dfs(int pos,int www,long long addt)
{
	if(pos>k)
	{
		long long sum=0;
		for(node w:las)
		{
			sum+=w.w;
//			cerr<<">>"<<w.u<<" "<<w.v<<" "<<w.w<<endl;
		}
//		cerr<<www<<"::"<<addt<<" + "<<sum<<endl;
		ans=min(ans,addt+sum);
		return;
	}
	vector<node> aaa=las;
	dfs(pos+1,www,addt);
	las=aaa;
	int tot=las.size();
	for(node w:edgec[pos])
	 las.push_back(w);
	inplace_merge(las.begin(),las.begin()+tot,las.end());
	dsu.init(n+k);
	tmp.clear();
	for(node w:las)
	if(dsu.merge(w.u,w.v))
	 tmp.push_back(w);
	las=tmp;
	dfs(pos+1,www|(1<<(pos-1)),addt+c[pos]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back(node{u,v,w});
	}
	sort(edges.begin(),edges.end());
	tmp.clear();
	dsu.init(n+k);
	for(node w:edges)
	if(dsu.merge(w.u,w.v))
	 tmp.push_back(w);
	edges=tmp;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			edgec[i].push_back(node{n+i,j,a[i][j]});
		}
		sort(edgec[i].begin(),edgec[i].end());
	}
	las=edges;
	dfs(1,0,0);
	cout<<ans<<endl;
}
