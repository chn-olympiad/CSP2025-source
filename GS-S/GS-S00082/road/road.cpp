#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1e6,maxn=1e4;
typedef long long ll;

struct edge
{
	int w,u;
	ll v;
	bool operator <(const edge &b)
	{
		return w<b.w;
	}
}e[maxm+5];
int fa[maxn+5],dd[15][maxn+5];
int n,m,k;
int find(int x)
{
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}

ll solve(int sta)
{
	ll ans=0,cnt;
	for(int i=1;i<=k;++i)
	{
		if(sta&(1<<(k-1)))ans+=dd[i][0];
	}
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv)
		{
			ll x=1e10;
			if(sta&(1<<(e[i].u-1)))
			{
				x=min(x,1ll*dd[e[i].u][e[i].v]);
			}
			if(sta&(1<<(e[i].v-1)))
			{
				x=min(x,1ll*dd[e[i].v][e[i].u]);
			}
			fa[fv]=fu,ans+=min(1ll*e[i].w,x);
			cnt++;
		}
        //cout<<e[i].v<<" "<<e[i].u<<" "<<e[i].w<<"\n";
	}
	if(cnt<n-1)return 1e18;
	else return ans;
}

int main()
{
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	//freopen("test.txt","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<=n;++j)cin>>dd[i][j];
	}
	sort(e+1,e+m+1);
	ll ans=1e18;
	for(int i=1;i<=(1<<k)-1;++i)
	{
		ans=min(ans,solve(i));
	}
	cout<<ans;
	//cout<<k;
	
	/*
	4 2 0
	1 4 6
	2 3 7
	4 2 5
	4 3 4
	1 1 8 2 4
	100 1 3 2 4
	*/
	return 0;
}
