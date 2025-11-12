#include<bits/stdc++.h>
#define int long long
using namespace std;
const int K=12;
const int N=1e4+100;
int n,m,k,c[K],a[K][N],ans,fa[N];
struct zz
{
	int x,y,z;
	bool operator < (const zz&other) const
	{
		return z<other.z;
	}
};
vector<zz>g[1<<K],tmp,d[K];
int find(int x)
{
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	return x;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;ans=LONG_LONG_MAX;
	for(int i=1,x,y,z;i<=m;i++)
	{
		cin>>x>>y>>z;
		tmp.push_back({x,y,z});
	}
	sort(tmp.begin(),tmp.end());
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j],d[i].push_back({i+n,j,a[i][j]});
		sort(d[i].begin(),d[i].end());
	}
	int now=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(auto to:tmp)
	{
		int x=to.x,y=to.y,z=to.z;
		int a=find(x),b=find(y);
		if(a!=b)
		{
			fa[a]=b;
			now+=z;
			g[0].push_back(to);
		}
	}
	ans=min(ans,now);
	for(int S=1;S<(1<<k);S++)
	{
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int st=0;now=0;
		for(int i=0;i<k;i++)if((S>>i)&1)now+=c[i+1];
		for(int i=0;i<k;i++)if((S>>i)&1){st=i+1;break;}
		int SS=S^(1<<(st-1));
		tmp=g[SS];
		int lent=tmp.size();
		for(auto to:d[st])tmp.push_back(to);
		inplace_merge(tmp.begin(),tmp.begin()+lent,tmp.end());
		for(auto to:tmp)
		{
			int x=to.x,y=to.y,z=to.z;
			int a=find(x),b=find(y);
			if(a!=b)
			{
				fa[a]=b;
				now+=z;
				g[S].push_back(to);
			}
		}
		ans=min(ans,now);
	}
	cout<<ans;
	return 0;
}
