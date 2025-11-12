#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+100;
const int M=1e6+100;
int n,m,k,v[N],ans;
bool u[N];
int fa[N];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
void uni(int x,int y)
{fa[find(y)]=find(x);}
struct edge
{
	int x,y,d;
}e[N+M];
bool cmp(edge a,edge b)
{return a.d<b.d;}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].d;
	for(int i=1;i<=n;i++)
			fa[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1,s=0;i<=m&&s<n-1;i++)
		if(find(e[i].x)!=find(e[i].y))
			ans+=e[i].d,uni(e[i].x,e[i].y),s++;
	for(int i=1;i<=k;i++)
	{
		cin>>v[i];
		for(int j=1;j<=n;j++)
		{
			int d;cin>>d;
			e[++m]={j,i+n,d};
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int t=1;t<(1<<k);t++)
	{
		int sum=0,use=0;
		for(int i=1;i<=k;i++)
			if((t>>(i-1))&1)
				sum+=v[i],
				use++,
				u[n+i]=1;
			else u[n+i]=0;
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		for(int i=1,s=0;i<=m&&s<n+use-1;i++)
			if(find(e[i].x)!=find(e[i].y))
			if(e[i].x<=n||u[e[i].x]==1)
			if(e[i].y<=n||u[e[i].y]==1)
				sum+=e[i].d,uni(e[i].x,e[i].y),s++;
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
