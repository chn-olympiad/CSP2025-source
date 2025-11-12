#include<bits/stdc++.h>
#define int long long
#define N 10005
#define f first
#define s second
using namespace std;
constexpr int INF=0x3f3f3f3f3f3f3f3f;

int n,m,k;
int u,v,w;
array<array<int,N>,N> g;
array<pair<int,array<int,N> >,15> p;

int ans;
array<bool,N> val;

void dfs(int rt,int sum,int num)
{
	if(sum>num) return; 
	if(num==n)
	{
		ans=min(ans,sum);
		return;
	}

	for(int i=1;i<=n;i++)
	if(g.at(rt).at(i)!=INF && !val.at(i) )
	{
		val.at(i)=true;
		dfs(i,sum+g.at(rt).at(i),num+1);
		val.at(i)=false;
	}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
    ans=INF;
	cin>>n>>m>>k;
	val.fill(false);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	g.at(i).at(j)=INF;
	
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		g.at(u).at(v)=g.at(v).at(u)=w;
	}

    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&p.at(i).f);
        for(int j=1;j<=n;j++)
        scanf("%lld",&p.at(i).s.at(j) );
    }
	
	val.at(1);
	dfs(1,0,1);
	cout<<ans<<endl;// ¡£¡£¡£ 
	return 0;
}
