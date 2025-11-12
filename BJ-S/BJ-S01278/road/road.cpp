#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#define cin lyc
#define cout lmy
//cin loves cout!
ifstream cin("road.in");
ofstream cout("road.out");
struct edge
{
	int u,v,w,cond;
	edge(){}
	edge(int uu,int vv,int ww,int cc=-1):u(uu),v(vv),w(ww),cond(cc){}
	bool operator < (const edge& b) const
	{
		return w<b.w;
	}
};
vector<edge> g;
int n,m,k,fa[20005],sz[20005],c[15];
int get(int u){return (u==fa[u])?u:(fa[u]=get(fa[u]));}
void comb(int u,int v)
{
	if((u=get(u))==(v=get(v)))	return;
	if(sz[u]<sz[v])	swap(u,v);
	fa[v]=u;
	sz[u]+=sz[v];
}
long long solve(int s)
{
	for(int i=0;i<=n+k;i++)	fa[i]=i,sz[i]=1;
	int cnt=n-1;
	long long ans=0;
	for(int i=0;i<k;i++)
		if(s&(1<<i))
			ans+=c[i],cnt++;
	for(edge e:g)
		if(get(e.u)!=get(e.v) && (e.cond==-1 || s&(1<<e.cond)))
		{
			comb(e.u,e.v);
			ans+=e.w;
			if(!--cnt)	return ans;
		}
	return 5e18;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1,x,y,w;i<=m;i++)	cin>>x>>y>>w,g.emplace_back(x,y,w);
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=1,x;j<=n;j++)
			cin>>x,g.emplace_back(i+n+1,j,x,i);
	}
	sort(g.begin(),g.end());
	long long ans=1e18;
	for(int i=0;i<(1<<k);i++)
		ans=min(ans,solve(i));
	cout<<ans<<endl;
}