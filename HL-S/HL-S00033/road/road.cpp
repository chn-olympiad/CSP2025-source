#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e4+5,M=1e6+1e5+5;
struct edge{
	int id;
	int u,v,w;
}e[M],xc[15*N];
int fa[N];
int get(int x)
{
	if(fa[x]==x)	return x;
	return fa[x]=get(fa[x]);
}
int n,m,k,ans,c[15];
bool cmp1(edge x,edge y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)	cin>>e[m+(i-1)*n+j].w,e[m+(i-1)*n+j].u=n+i,e[m+(i-1)*n+j].v=j;
	}
	n=n+k,m=m+k*n;
	for(int i=1;i<=n;i++)	fa[i]=i;
	int cnt=n;
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=m;i++)
	{
		if(cnt==1)	break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		u=get(u),v=get(v);
		if(u==v)	continue;
		fa[u]=v,ans+=w,cnt--;
	}
	cout<<ans;
	return 0;
}
//48pts
