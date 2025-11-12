#include<bits/stdc++.h>
#define ll long long
#define R register
#define endl '\n'
#define N 10206
#define M 1000006
using namespace std;
int n,m,tot,sz,k;
ll a[N],ans,sum;
struct Edge {int u,v;ll w;}E[M],pre[M<<1],now[M<<1],c[16][N];
inline bool operator <(const Edge &x,const Edge &y){return x.w<y.w;}
struct UFS {
	int fa[N];
	inline void init(){for(R int i=1;i<=n+k;i++)fa[i]=i;}
	inline int find(int k){return fa[k]==k?k:fa[k]=find(fa[k]);}
	inline void merge(int u,int v){u=find(u),v=find(v);if(u!=v)fa[v]=u;}
}S;
template <typename T>
inline T read()
{
	T f=1,ret=0; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar();
	return ret*f;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read<int>(),m=read<int>(),k=read<int>(),S.init();
	for(R int i=1;i<=m;i++)E[i].u=read<int>(),E[i].v=read<int>(),E[i].w=read<ll>();
	sort(E+1,E+1+m);
	for(R int i=1;i<=m;i++)
	{
		int u=E[i].u,v=E[i].v;ll w=E[i].w;
		if(S.find(u)!=S.find(v))S.merge(u,v),E[++tot]=E[i],ans+=w;
	}
	for(R int i=1;i<=k;i++)
	{
		a[i]=read<ll>(); ll x;
		for(R int j=1;j<=n;j++)
			x=read<ll>(),c[i][j]={i+n,j,x};
		sort(c[i]+1,c[i]+1+n);
	}
	for(R int T=0;T<(1<<k);T++)
	{
		sum=0,sz=tot,S.init();
		for(R int i=1;i<=tot;i++)pre[i]=E[i];
		for(R int i=1;i<=k;i++)if(T>>(i-1)&1)
		{
			sum+=a[i];
			R int now_sz=0,p,q;
			for(p=1,q=1;p<=sz&&q<=n;)
			{
				if(pre[p].w<c[i][q].w)now[++now_sz]=pre[p++];
				else now[++now_sz]=c[i][q++];
			}
			for(;p<=sz;p++)now[++now_sz]=pre[p];
			for(;q<=n;q++)now[++now_sz]=c[i][q];
			sz=now_sz;
			for(R int j=1;j<=sz;j++)pre[j]=now[j];
		}
		for(R int i=1;i<=sz;i++)
		{
			int u=pre[i].u,v=pre[i].v,w=pre[i].w;
			if(S.find(u)!=S.find(v))sum+=w,S.merge(u,v);
			if(sum>=ans)break;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
