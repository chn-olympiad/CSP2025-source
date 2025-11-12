#include<bits/stdc++.h>
#define N 10005
#define M 1000005
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,k;
struct edge
{
	int u,v;
	long long w;
	bool operator <(const edge& b)const
	{
        if(w!=b.w) return w<b.w;
        if(u!=b.u) return u<b.u;
        return v<b.v;
	}
};
vector<edge> s;
long long c[15],a[15][N],ans=inf;
int fa[N+15],sz[N+15];
int find(int x) {return x==fa[x]?x:(fa[x]=find(fa[x]));}
void join(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
	return;
}
void init() {for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;}
long long kruscal(int cnt)
{
	long long res=0;
	sort(s.begin(),s.end());
	vector<edge> tmp;
	init();
	for(auto e:s) if(sz[find(1)]<cnt&&find(e.u)!=find(e.v))
	{
		res+=e.w;
		join(e.u,e.v);
		tmp.push_back(e);
	}
	swap(s,tmp);
	return res;
}
void dfs(int dep,long long sum,int cnt)
{
	if(dep==k+1) return;
	dfs(dep+1,sum,cnt);
	vector<edge> tmp(s);
	for(int i=1;i<=n;i++) s.push_back({n+dep,i,a[dep][i]});
	ans=min(ans,kruscal(n+cnt+1)+sum+c[dep]);
	dfs(dep+1,sum+c[dep],cnt+1);
	swap(tmp,s);
	return;
}
void solve()
{
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) if(!a[i][j])
	{
		for(int k=1;k<=n;k++) if(k!=j)
		{
			s.push_back({j,k,a[i][k]});
		}
	}
	cout<<kruscal(n)<<'\n';
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	int u,v,w;
    	cin>>u>>v>>w;
    	s.push_back({u,v,w});
	}
	bool flg=true;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) flg=false;
		bool tmp=false;
		for(int j=1;j<=n;j++) cin>>a[i][j],tmp=tmp||(a[i][j]==0);
		if(!tmp) flg=false;
	}
	if(k==0) return cout<<kruscal(n)<<'\n',0;
	if(flg) return solve(),0;
	ans=kruscal(n);
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
