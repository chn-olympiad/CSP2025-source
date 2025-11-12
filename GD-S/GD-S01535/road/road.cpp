#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool st;
const int N=1e6+4445,M=1e4+445;
struct node{
	int x,y;
	ll len;
}g[N],e[N],h[N];
int n,m,k;
int f[M],tot=0;
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(node x,node y)
{
	return x.len<y.len;
}
ll c[20],a[20][M];
ll ans=1e18;
bool ed;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cerr<<(&ed-&st)/1048576.0000<<"\n";
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		ll w;
		cin>>x>>y;
		cin>>w;
		e[i].x=x;
		e[i].y=y;
		e[i].len=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	//return 0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=e[i].x,y=e[i].y;
		if(find(x)!=find(y))
		{
			f[find(y)]=find(x);
			g[++tot]=e[i];
		}
	}
//	cerr<<"tot="<<tot<<"\n";
	ll ans=1e18;
	for(int S=0;S<(1<<k);S++)
	{
		ll az=0;
		int cnt=0;
		for(int i=1;i<=k;i++) 
		{
			if(S&(1<<(i-1)))
			{
				az+=c[i];
				for(int j=1;j<=n;j++) h[++cnt].x=n+i,h[cnt].y=j,h[cnt].len=a[i][j];
			}
		}
		for(int i=1;i<=tot;i++) h[++cnt]=g[i];
		sort(h+1,h+1+cnt,cmp);
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=cnt;i++)
		{
			int x=h[i].x,y=h[i].y; 
			if(find(x)!=find(y))
			{
				f[find(y)]=find(x);
				az+=h[i].len;
			}
		} 
		ans=min(ans,az);
	}
	cout<<ans;
} 
