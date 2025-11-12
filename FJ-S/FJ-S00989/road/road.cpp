#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
const int N=1e4+5,M=1e6+5;
const ll INF=1e18;
int n,m,k,c[11][N],fa[N],cnt=0;
ll ans=0;
bool iscit[11];
set<int> st[N];
struct node
{
	int u,v,w;
	inline bool operator<(const node& rhs) const {return w<rhs.w;}
} e[M];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int u,int v)
{
	u=find(u);
	v=find(v);
	for(int x:st[u])
		st[v].insert(x);
	fa[u]=v;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		st[i].insert(i);
	}
	for(int i=1;i<=m;++i)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<=n;++j)
			c[i][j]=read();
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;++i)
	{
		if(cnt==n-1)
			break;
		if(find(e[i].u)==find(e[i].v))
			continue;
		ll minn=e[i].w;
		for(int j=1;j<=k;++j)
		{
			if(!iscit[j]&&minn<=c[j][0])
				continue;
			ll bas=iscit[j]?0:c[j][0];
			for(int u:st[find(e[i].u)])
			{
				if(minn<=bas+c[j][u])
					continue;
				for(int v:st[find(e[i].v)])
				{
					if(minn>=bas+c[j][u]+c[j][v])
					{
						minn=bas+c[j][u]+c[j][v];
						iscit[j]=1;
					}
				}
			}
		}
		++cnt;
		merge(e[i].u,e[i].v);
		ans+=minn;
	}
	printf("%lld",ans);
	return 0;
}
