#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+5,M=1e6+5,K=15;

struct node{
	ll w;
	int u,v;
	bool operator < (const node &x) const
	{
		if(w!=x.w) return w<x.w;
		if(u!=x.u) return u<x.u;
		return v<x.v;
	}
};

int n,m,k,fa[N];
ll ans=1e17;
vector<node> yt;
set<node> s;
ll c[K][N];

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

void dfs(int pos,ll tot,int cnt)
{
	if(pos>k)
	{
		cnt+=n-1;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		set<node>::iterator it=s.begin();
		int p=0;
		for(;;)
		{
			int tu,tv;
			ll tw;
			if(it==s.end() or yt[p].w<=(*it).w)
			{
				tu=yt[p].u,tv=yt[p].v,tw=yt[p].w;
				p++;
			}
			else 
			{
				tu=(*it).u,tv=(*it).v,tw=(*it).w;
				it++;
			}
			if(find(tu)!=find(tv))
			{
				fa[find(tu)]=find(tv);
				tot+=tw;
				cnt--;
			}
			if(cnt<=0) break;
			if(it==s.end() and p==(int)yt.size()) break;
		}
		if(cnt<=0) ans=min(ans,tot);
		return ;
	}
	for(int i=1;i<=n;i++)
		s.insert((node){c[pos][i],pos+n,i});
	dfs(pos+1,tot+c[pos][0],cnt+1);
	for(int i=1;i<=n;i++)
		s.erase((node){c[pos][i],pos+n,i});
	dfs(pos+1,tot,cnt);
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		node t;
		scanf("%d%d%lld",&t.u,&t.v,&t.w);
		yt.push_back(t);
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			scanf("%lld",&c[i][j]);
	sort(yt.begin(),yt.end());
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
