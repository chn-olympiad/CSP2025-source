#include<bits/stdc++.h> 
using namespace std;
const int N=1e4+100,M=1e6+10,K=15;

int n,m,k;

struct Edge
{
	int u,v,w;
	int id;	
	
	bool operator < (const Edge & edge)const 
	{
		return w>edge.w;
	}
}g[K][N];

int c[15];

long long ans=LONG_LONG_MAX;


long long res=0,f[N],sz[N];
int gf(int x)
{
	if(f[x]==x)return x;
	return f[x]=gf(f[x]);
}

priority_queue<Edge>q;
bool nd[K],ls[K];

vector<Edge>awa;

void solve()
{
	res=0;
	int uk=0;
	
	for(int i=1;i<=n+k;i++) f[i]=i,sz[i]=1;
	for(int i=1;i<=k;i++)
	{
		if(nd[i]==1)res+=c[i],uk++;
		if(res>=ans)return ;
	//	if(nd[i])for(int j=1;j<=n;j++)q.push(g[i][j]);
		if(ls[i]==0 and nd[i]==1)
		{
			for(int j=1;j<=n;j++)
				q.push(g[i][j]);
		}
		ls[i]=nd[i];
	}
	
	for(auto vv :awa) q.push(vv);
	
	int cnt=0;
	while(cnt<n+uk-1)
	{
		int id=q.top().id;
		if(nd[id]==false) 
		{
			q.pop();
			continue;
		}
		int u=q.top().u,v=q.top().v,w=q.top().w;
		
		if(id==0) awa.push_back(q.top());
		q.pop();
		
		
		int fu=gf(u),fv=gf(v);
		if(fu==fv) continue;
		
		if(sz[fu]>sz[fv]) swap(fu,fv);
		f[fu]=fv; sz[fv]+=sz[fu];
		res+=w;
		cnt++;
		if(res>=ans) return ;
	}
	return ;
}
bool STA(int t) 
{
	if(t==k+1)
	{
		res=0;
//		for(int i=1;i<=k;i++) cout<<nd[i];cout<<endl;
	
		solve();
		if(res<ans)
		{
			ans=res;
			return true;
		}
		return false;
	}
	
	nd[t]=0;
	if(STA(t+1)) 
		return false;
	
	nd[t]=1;
	STA(t+1);
	nd[t]=0;
	
	return true;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		Edge node; 
		cin>>node.u>>node.v>>node.w;node.id=0;
		q.push(node);
	}
	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			g[i][j].u=n+i;
			g[i][j].v=j;
			cin>>g[i][j].w;
			g[i][j].id=i;
		}
	}

	
	nd[0]=1; ls[0]=1;
	STA(1);
	
	cout<<ans;
	
	return 0;
}
/*
rp++ 
*/ 
