//(nac(n)+nk)*2^k希望能过 
#include<bits/stdc++.h>
using namespace std;
#define K 13
#define N 10005
#define M 1000005 
#define lxl long long
#define INF 1000000000000000000
#define il inline
namespace lzz
{
	int n,m,k,c[N],a[K][N],dui[K][N];
	struct kkk{int to,next;}ed[N*K];//桶排
	int head[N*K],tot; void add(int x,int y){ed[++tot]={y,head[x]},head[x]=tot;} 
	struct edge
	{
		int u,v,w;
		bool operator<(const edge &b)const
		{
			return w<b.w;
		}
	}t[M]; int hv,lim; bool is[M];
	int fa[N+K],sz[N+K];
	il void init(){for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;}
	il int find(int x){return (x==fa[x])?x:fa[x]=find(fa[x]);}
	il bool merge(int u,int v)
	{
		u=find(u),v=find(v);
		if(u^v)
		{
			if(sz[u]<sz[v])swap(u,v);
			fa[v]=u,sz[u]+=sz[v]; return 1;
		}return 0;
	}int b[N*K],o;//离散化,用来桶排 
	il void build()
	{
		init(),sort(t+1,t+m+1);
		for(int i=1;i<=m;i++)
		{
			if(merge(t[i].u,t[i].v))is[i]=1;
		}
	}
	il lxl solve(int sz)
	{
		int num=0; lxl res=0; init();
		for(int i=1;i<=o;i++)
		{
			if(num!=n+sz-1)
			{
				for(int j=head[i];j;j=ed[j].next)
				{
					if(merge(t[ed[j].to].u,t[ed[j].to].v))res+=b[i],num++;
				}	
			}head[i]=0;//用完清空 
		}tot=0; return res;
	}
	int main()
	{
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>t[i].u>>t[i].v>>t[i].w; build();
		for(int i=1;i<=m;i++)
		{
			if(!is[i])continue;
			b[++o]=t[i].w,t[o]=t[i];
		}lim=o;//只用这些边 
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)cin>>a[i][j],t[++o]={n+i,j,a[i][j]},b[o]=a[i][j],dui[i][j]=o;
		}hv=o,sort(b+1,b+o+1),o=unique(b+1,b+o+1)-b-1;//记hv为离散化前的大小 
		for(int i=1;i<=hv;i++)t[i].w=lower_bound(b+1,b+o+1,t[i].w)-b;
		lxl ans=INF;
		for(int i=0;i<(1<<k);i++)
		{
			lxl all=0,num=0;//启动费用 
			for(int j=0;j<k;j++)
			{
				if((i>>j)&1)
				{
					num++,all+=c[j+1];
					for(int p=1;p<=n;p++)add(t[dui[j+1][p]].w,dui[j+1][p]);
				}
			}for(int j=1;j<=lim;j++)add(t[j].w,j); ans=min(ans,solve(num)+all);
		}cout<<ans<<'\n';
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}

