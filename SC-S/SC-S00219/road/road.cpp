//road.cpp
//expect: 80~100pts
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=1e4+114;
int n,m,k,C[mxn],c[11][mxn],nwm,nwk,ans;
class conu
{
private:
	int fa[mxn];
public:
	inline void init(int n)
	{
		for (int i=1;i<=n;i++) fa[i]=i;
	}
	inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline bool merge(int u,int v)
	{
		u=find(u),v=find(v);
		if (u==v) return 0;
		fa[u]=v;
		return 1;
	}
}S;
struct edge
{
	int u,v,w;
}ed[2000060],e[mxn*10];
inline bool cmp(edge &x, edge &y)
{
	return x.w<y.w;
}
inline int get_cl(int tot)
{
	int nans=0,nwpos=1;
	tot+=n; tot--;
	S.init(n+k);int cnt=0;
	for (int i=1;i<=m;i++)
	{
		while (e[nwpos].w<=ed[i].w&&nwpos<=nwm)
		{
			if (S.merge(e[nwpos].u,e[nwpos].v)) nans+=e[nwpos].w,cnt++;
			nwpos++;
		}
		if (S.merge(ed[i].u,ed[i].v)) nans+=ed[i].w,cnt++;
		if (cnt==tot) break;
	}
	return nans;
}
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w; ed[i]={u,v,w};
	}sort(ed+1,ed+1+m,cmp);
	ans=1e18+114;
	for (int i=1;i<=k;i++)
	{
		cin>>C[i];
		for (int j=1;j<=n;j++) cin>>c[i][j];
	}
	for (int i=0;i<(1<<k);i++)
	{
		int nans=0; nwm=0; nwk=0;
		for (int j=1;j<=k;j++)
		{
			if ((i>>(j-1))&1)
			{
				nans+=C[j];nwk++;
				for (int f=1;f<=n;f++)
				{
					e[++nwm]={n+j,f,c[j][f]};
				}
			}
		}
		sort(e+1,e+nwm+1,cmp);
		ans=min(ans,get_cl(nwk)+nans);
	}
	cout<<ans<<'\n';
	return 0;
}