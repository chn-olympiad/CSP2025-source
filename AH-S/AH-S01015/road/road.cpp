
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e4+1,M=1e6+1;
ll n,m,k,a[N],cnt,fa[N],num;
ll ans;
int get(int x){return (fa[x]==x)?x:fa[x]=get(fa[x]);}
struct node{ll u,v,w;}e[M*3];

bool cmp(const node &x,const node &y)
{
	return x.w<y.w;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	
	for(int i=1,x;i<=k;i++)
	{
		cin>>a[0];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]==0)
				x=j;
		}
		for(int j=1;j<=n;j++)
			if(j!=x)
				e[++cnt]={x,j,a[j]};
	}
	
	sort(e+1,e+1+cnt,cmp);
	
	for(int i=1;i<=cnt;i++)
	{
		int u=get(e[i].u),v=get(e[i].v);
		if(u!=v)
		{
			fa[u]=v;
			ans+=e[i].w;
			num++;
			if(num==n-1)
				break;
		}
	}
	cout<<ans;
	return 0;
}
