#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 2010
#define inf 0x3f3f3f3f3f3f3f3f
int n,m,k,fa[maxn],sz[maxn],tp,nn,szz;
void init()
{
	for(int i=1;i<=nn;++i) fa[i]=i,sz[i]=1;
}
int find(int n)
{
	return n==fa[n]?n:fa[n]=find(fa[n]);
}
void uni(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x]<sz[y])swap(x,y);
	fa[y]=x;
	sz[x]+=sz[y];
	sz[y]=0;
}
struct edge{
	int u,v,w;
	bool operator<(edge e)const
	{
		return w<e.w;
	}
}v[2000100],vv[2000100];
int pp[12][maxn],c[110];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	nn=n;
	for(int i=1;i<=m;++i)
	{
		++tp;
		cin>>v[tp].u>>v[tp].v>>v[tp].w;
	}
	for(int j=1;j<=k;++j)
	{
		cin>>c[j];
		if(c[j]==0)
		{
			++nn;
			for(int i=1;i<=n;++i)
			{
				++tp;
				v[tp].v=i;
				v[tp].u=nn;
				cin>>v[tp].w;
			}
		}
		else
		{
			++szz;
			for(int i=1;i<=n;++i)
			{
				cin>>pp[szz][i];
			}
		}
	}
	int ans=inf,cnt=0;
	int ttt=tp,l_n=nn;
	copy(v+1,v+tp+1,vv+1);
	for(int i=0;i<(1<<szz);++i)
	{
		cnt=0;
		init();
		for(int j=1;j<=szz;++j)
		{
			if(i&(1<<j-1))
			{
				++nn;
				for(int k=1;k<=n;++k)
				{
					++tp;
					v[tp].u=nn;
					v[tp].v=k;
					v[tp].w=pp[j][k];
				}
				cnt+=c[j];
			}
		}
		sort(v+1,v+tp+1);
		for(int j=1;j<=tp;++j)
		{
			if(find(v[j].u)==find(v[j].v))continue;
			uni(v[j].u,v[j].v);
			cnt+=v[j].w;
		}
		ans=min(ans,cnt);
		tp=ttt;
		copy(vv+1,vv+tp+1,v+1);
		nn=l_n;
	}
	cout<<ans<<'\n';
	return 0;
}
//k is small
