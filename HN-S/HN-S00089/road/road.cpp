#include <bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define _ read<int>()
#define int long long
#define rint register int
#define R register
template<class T>inline T read()
{
	T r=0,f=1;R char c=gc();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(isdigit(c)) r=(r<<1)+(r<<3)+(c^48),c=gc();
	return f*r;
}
inline void out(rint x)
{
	if(x<0) pc('-'),x=-x;
	if(x<10) pc(x+'0');
	else out(x/10),pc(x%10+'0');
}
const int N=1e4+10,K=15,M=1e6+10; 
vector<pair<int,int> >g[N+K];
int ans=1145141919810,a[N+K],n,m,k,f[N];
bitset<N>vis;
struct oi
{
	int u,v,w;
}b[M];
inline int find(rint x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline void dfs(rint u,rint sum)
{
	if(vis.count()==n)
	{
		ans=min(ans,sum);
		return;
	}	
	for(auto qwq:g[u])
	{
		rint v=qwq.first,w=qwq.second;
		if(!vis[v])
		{
			if(v<=n) vis[v]=1;
			dfs(v,sum+w+a[v]);
			if(v<=n) vis[v]=0;
		}
	}
}
inline bool cmp(const oi &x,const oi &y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=_,m=_,k=_; 
	if(k==0)
	{
		for(rint i=1;i<=n;i++) f[i]=i;
		for(rint i=1;i<=m;i++)
		{
			b[i]={_,_,_};
		}
		sort(b+1,b+m+1,cmp);
		ans=0;
		for(rint i=1;i<=m;i++)
		{
			rint u=b[i].u,v=b[i].v,w=b[i].w;
			rint fu=find(u),fv=find(v);
			if(fu==fv) continue;
			f[fu]=fv;
			ans+=w;
		}
	}
	else
	{
		for(rint i=1;i<=m;i++)
		{
			rint u=_,v=_,w=_;
			g[u].push_back({v,w});
			g[v].push_back({u,w}); 
		}
		for(rint i=1;i<=k;i++)
		{
			rint x=_;
			a[i+n]=x;
			for(rint j=1;j<=n;j++)
			{
				rint y=_;
				g[i+n].push_back({j,y});
				g[j].push_back({i+n,y});
			}
		}
		vis[1]=1;
		dfs(1,0);
	}
	out(ans);
	return 0;
}

