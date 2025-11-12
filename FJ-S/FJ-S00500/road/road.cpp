#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=1e4+114,M=2e6+114,K=11;
int n,m,k;
typedef std::tuple<ll,int,int> edge;
edge e[M],f[K][N];
struct dsu
{
	int f[N];
	void init(int _){std::iota(f,f+_+1,0);}
	int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
	bool merge(int x,int y){return x=find(x),y=find(y),(x!=y)&&(f[x]=y);}
}d;
ll a[K][N];

edge et[2][K*N+M];
// int etcnt,len[K];
// int merge(int S,int l=1,int r=k)
// {
// 	if(l==r&&)
// 	{
// 		if((S>>(l-1))&1)std::copy(f[l]+1,f[l]+n+1,
// }

inline ll solve(int S)
{
	ll res=0,c=0,len=0;
	// etcnt=0;
	for(int i=1;i<=k;i++)if((S>>(i-1))&1)
	{
		res+=a[i][0];
		std::copy(f[i]+1,f[i]+n+1,et[0]+len+1);
		len+=n;
	}
	std::sort(et[0]+1,et[0]+len+1);
	// for(int i=1;i<=k;i++)if((S>>(i-1))&1)
	// {
	// 	c^=1;
	// 	res+=a[i][0];
	// 	std::merge(et[c^1]+1,et[c^1]+len+1,f[i]+1,f[i]+n+1,et[c]+1);
	// 	len+=n;
	// }
	std::merge(et[0]+1,et[0]+len+1,e+1,e+m+1,et[1]+1);
	len+=m;
	d.init(n+k);
	for(int i=1;i<=len;i++)
	{
		auto [w,u,v]=et[1][i];
		if(d.merge(u,v))
		{
			res+=w;
		}
	}
	return res;
}

int main()
{
	fr(road)
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		auto&[w,u,v]=e[i];
		cin>>u>>v>>w;
	}
	std::sort(e+1,e+m+1);
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>a[i][j];
			if(j)f[i][j]=edge(a[i][j],n+i,j);
		}
		std::sort(f[i]+1,f[i]+n+1);
	}
	ll ans=4e18;
	for(int S=0;S<(1<<k);S++)
	{
		ans=std::min(ans,solve(S));
		// ll tmp=solve(S);
		// if(ans>tmp)fprintf(stderr,"*%d %lld\n",S,tmp);
	}
	printf("%lld",ans);
	return 0;
}
