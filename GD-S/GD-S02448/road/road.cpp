#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
using namespace std;

const int N=2e4+5,M=1e6+5;
int n,m,K;
int a[15][N],c[15],fa[N],mn[N];
struct node{
	int u,v,w;
}sd[M],b[M],b2[M];

inline int getfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}

inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0' || '9'<ch) ch=getchar();
	do x=(x<<1)+(x<<3)+(ch^48),ch=getchar(); while('0'<=ch && ch<='9');
	return x;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),K=read();
	for(int i=1;i<=m;i++)
		sd[i].u=read(),sd[i].v=read(),sd[i].w=read();
	for(int i=1;i<=K;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
	for(int i=1;i<=n;i++) a[0][i]=2e9;
	
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(sd+1,sd+1+m,[](auto x,auto y){
		return x.w<y.w;
	});
	int blen=0;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int u=sd[i].u,v=sd[i].v,w=sd[i].w;
		if(getfa(u)!=getfa(v))
		{
			ans+=w;
			b[++blen]=sd[i];
			fa[getfa(u)]=getfa(v);
		}
	}
	
	for(int s=1;s<1<<K;s++)
	{
		for(int i=1;i<=n+K;i++) 
		{
			mn[i]=0;
			fa[i]=i;
		}
		ll nowans=0;
		for(int i=1;i<=K;i++)
			if(s&(1<<i-1))
			{
				nowans+=c[i];
				for(int j=1;j<=n;j++)
					if(a[i][j]<a[mn[j]][j]) mn[j]=i;
			}
		
		ll bl2=blen;
		for(int i=1;i<=bl2;i++)
			b2[i]=b[i];
		for(int i=1;i<=n;i++)
			b2[++bl2]={i,mn[i]+n,a[mn[i]][i]};
		sort(b2+1,b2+1+bl2,[](auto x,auto y){
			return x.w<y.w;
		});
		
		for(int i=1;i<=bl2;i++)
		{
			int u=b2[i].u,v=b2[i].v,w=b2[i].w;
			if(getfa(u)!=getfa(v))
			{
				fa[getfa(u)]=getfa(v);
				nowans+=w;
			}
		}
		ans=min(ans,nowans);
	}
	printf("%lld",ans);
	return 0;
}

