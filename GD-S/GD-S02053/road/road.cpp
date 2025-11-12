#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int u,v,w;
	bool operator<(edge &b)const
	{
		return w<b.w;
	}
}e[1000010];
int c[20],a[20][10010],n,m,k,fa[10020];
vector<edge> vc,ne,ue;
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int solve(int sta)
{
	int ret=0,nk=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=0;i<k;i++) if(sta>>i&1) ret+=c[i+1];
	vc.clear();
//	cout<<"nk="<<nk<<'\n';
	int pt1=0,pt2=0;
	while(pt1<ue.size()||pt2<ne.size())
	{
		if(pt1>=ue.size())
		{
			if(sta>>(ne[pt2].u-n-1)&1)
			vc.push_back(ne[pt2]);
			pt2++;
			continue;
		}
		if(pt2>=ne.size())
		{
			vc.push_back(ue[pt1]);
			pt1++;
			continue;
		}
		if(ue[pt1]<ne[pt2])
		{
			vc.push_back(ue[pt1]);
			pt1++;
		}
		else
		{
			if(sta>>(ne[pt2].u-n-1)&1)
			vc.push_back(ne[pt2]);
			pt2++;
		}
	}
//	assert(vc.size()==ue.size());
	int cnt=0,pc=__builtin_popcount(sta);
	for(auto ed:vc)
	{
		int u=ed.u,v=ed.v,w=ed.w;
//		cout<<"u,v,w="<<u<<','<<v<<','<<w<<'\n';
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		ret+=w;
		fa[fu]=fv;
		cnt++;
		if(cnt==n+pc-1) break;
	}
	return ret;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1);
	int ncnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		ue.push_back(e[i]);
		fa[fu]=fv;
//		cout<<"choose "<<i<<'\n';
		ncnt++;
		if(ncnt==n-1) break;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++) ne.push_back({i+n,j,a[i][j]});
	}
	sort(ne.begin(),ne.end());
//	for(int i=1;i<=n;i++) if(find(i)!=find(1)) assert(0);
	int ans=1e18;
//	solve(1);
//	cout<<'\n';
	for(int sta=0;sta<(1<<k);sta++) ans=min(ans,solve(sta));
	cout<<ans;
}
