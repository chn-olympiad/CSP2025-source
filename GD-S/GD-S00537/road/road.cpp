#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N=10005,K=15;

int n,m,k;
long long c[K];

struct edge
{
	int u,v;
	long long w;
	
	bool operator<(const edge &e) const {return w>e.w;}
	bool operator>(const edge &e) const {return w<e.w;}
};

vector<edge> e,t,ec[K];

int uf[N+K],sz[N+K];

void init()
{
	for(int i=1;i<=n+k;i++) uf[i]=i,sz[i]=1;
}

int find(int x)
{
	return uf[x]==x?x:find(uf[x]);
}

void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x]<sz[y]) swap(x,y);
	sz[x]+=sz[y],uf[y]=x;
}

priority_queue<edge> q;

long long solve(int x)
{
	init();
	
	long long res=0;
	
	for(int i=1;i<=k;i++)
	{
		if((x>>(i-1))&1==1)
		{
			res+=c[i];
			for(int j=0;j<ec[i].size();j++) q.push(ec[i][j]);
		}
	}
	
	for(int i=0;i<e.size();i++) q.push(e[i]);
	
	while(!q.empty())
	{
		int u=q.top().u,v=q.top().v,w=q.top().w; q.pop();
		u=find(u),v=find(v);
		if(u==v) continue;
		
		res+=w,merge(u,v);
	}
	return res;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v; long long w; cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			long long w; cin>>w;
			ec[i].push_back({j,n+i,w});
		}
	}
	
	init();
	
	long long ans=0;
	
	while(!q.empty())
	{
		int u=q.top().u,v=q.top().v,w=q.top().w; q.pop();
		u=find(u),v=find(v);
		if(u==v) continue;
		
		ans+=w,merge(u,v),e.push_back({u,v,w});
	}
	
	for(int i=1;i<(1<<k);i++) ans=min(ans,solve(i));
	
	cout<<ans;
	
	return 0;
}
