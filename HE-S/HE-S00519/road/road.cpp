#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+100,maxk=15,maxm=1e6+10;
int p[maxn+maxk],cost[maxk],kedges[maxk][maxn];
int n,m,k;

struct edge{
	int from,to,dist;
	
//	edge(int u,int v,int w):from(u),to(v),dist(w){}
	
	bool operator <(const edge& a)
	{
		return dist<a.dist;
	}
}

edges[maxm],alledges[maxm+maxk*maxn];



vector<edge> mst;
int find(int x)
{
	return p[x]=x? x:p[x]=find(p[x]);
}
int kruskal(int k)
{	int cnt=0,ans=0;
	for(int i=1;i<=m;++i)
	{
		int u=alledges[i].from,v=alledges[i].to,w=alledges[i].dist,pu=find(u),pv=find(v);
		if(pu!=pv)
		{
			mst.push_back({u,v,w});
			ans+=w;
			p[u]=p[v];
			cnt++;
			if(cnt==n+k-1)break;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i)
	{
		cin>>u>>v>>w;
		edges[i]=edge{u,v,w};
		
	}
	
	for(int i=1,tmp;i<=k;++i)
	{	cin>>cost[i];
		for(int j=1;j<=n;++i)
		{
		cin>>tmp;
		kedges[i][j]=tmp;}
	}
//	cout<<1<<endl;
	for(int i=1;i<maxn+k;++i)
	{
		p[i]=i;
	}
	for(int i=1;i<=m;++i)
	{
		alledges[i].from=edges[i].from,alledges[i].to=edges[i].to,alledges[i].dist=edges[i].dist;
	//	cout<<alledges[i].dist<<endl;
	}
//	cout<<2<<endl;
	sort(alledges+1,alledges+1+m);

//	cout<<alledges[1].dist<<alledges[2].dist;
	int ans=kruskal(0);
	cout<<ans<<endl;
//	int comb=pow(2,k)
//	
//	for(int i=1;i<=comb;++i)
//	{
//		for(int j=)
//	}
	
	
}

