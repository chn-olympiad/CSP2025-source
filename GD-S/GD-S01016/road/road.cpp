#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int N=1e4+50;
const int M=2e6+50;
const int K=20;
int to[M<<1],ne[M<<1],ww[M<<1],h[N];
int c[K],a[K][N];
int fa[N];
int n,m,k,idx,cnt,ans;
piii lk[M];
//priority_queue< piii,vector<piii>,greater<piii> > q;
void add(int u,int v,int w)
{
	to[++idx]=v;
	ww[idx]=w;
	ne[idx]=h[u];
	h[u]=idx;
}
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i)
	{
		fa[i]=i;
	}
	int x,y,z;
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y>>z;
//		add(x,y,z);
//		add(y,x,z);
		lk[++cnt]={z,{x,y}};
	}
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			{
				fa[n+i]=j;
			}
			else
			{
				lk[++cnt]={a[i][j],{n+i,j}};
			}
		}
	}
	sort(lk+1,lk+cnt+1);
	int sum=0;
	for(int i=1;sum<n-1&&i<=cnt;++i)
	{
		x=lk[i].se.fi;
		y=lk[i].se.se;
		if(find(x)==find(y))
		{
			continue;
		}
		fa[find(x)]=find(y);
		ans+=lk[i].fi;
		++sum;
	}
	cout<<ans<<"\n";
}
