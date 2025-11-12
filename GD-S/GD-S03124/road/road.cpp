#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+5,N=1e4+5;
int n,m,k,ans,fa[N],siz[N];
struct edge
{
	int u,v,w;
	bool operator<(const edge x)const
	{
		return w>x.w;
	}
}a[M];
priority_queue<edge> q;
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		q.push(a[i]);
	}
	for(int i=1;i<=n;++i)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<n;++i)
	{
		edge u=q.top();
		q.pop();
		int x=find(u.u),y=find(u.v);
		if(x==y)
			continue;
		if(siz[x]>siz[y])
			swap(x,y);
		if(siz[x]==siz[y])
			siz[y]++;
		fa[x]=y;
		ans+=u.w;
	}
	cout<<ans;
	return 0;
}
