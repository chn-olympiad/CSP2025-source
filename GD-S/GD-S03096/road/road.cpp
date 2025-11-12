#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

const int N=1e4,M=3e6,K=10;

struct edge
{
	long long x,y,v;
	
	bool friend operator<(const edge& x,const edge& y)
	{
		if(x.v^y.v) return x.v<y.v;
		else return (x.x^y.x?x.x<y.x:x.y<y.y);
	}
};

int n,m,k;
edge e[M+1],l[M+1];
long long c[K+1],val[K+1][N+1];

int fa[N+K+1];

long long ans=1e18;

inline int find(int x)
{
	while(x^fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
inline long long check(int o)
{
	for(int i=1;i<=m+n*o;i++) l[i]=e[i];
	sort(l+1,l+1+m+n*o);
	
	long long res=0;
	for(int i=1;i<=n+o;i++) fa[i]=i;
	for(int i=1;i<=m+n*o;i++)
	{
		int x=find(l[i].x),y=find(l[i].y);
		
		if(fa[x]==fa[y]) continue;
		
		fa[x]=fa[y];
		res+=l[i].v;
	}
	//cout<<res<<'\n';
	return res;
}

inline void dfs(int pos,long long sum,int len)
{
	if(pos>k)
	{
		//cout<<sum<<'\n';
		ans=min(ans,sum+check(len));
		return;
	}
	
	dfs(pos+1,sum,len);
	for(int i=1;i<=n;i++) e[m+n*len+i]={n+len+1,i,val[pos][i]};
	dfs(pos+1,sum+c[pos],len+1);
	
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].x>>e[i].y>>e[i].v;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>val[i][j];
	}
	
	dfs(1,0,0);
	
	cout<<ans;
	
	return 0;
}

