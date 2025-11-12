#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
constexpr int N=1e4,M=1e6,K=10;
int read()
{
	int re=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		re=re*10+(c^'0');
		c=getchar();
	}
	return re;
}
struct edge
{
	int u,v,w;
};
edge e[M+5],t[M+K*N+5];
int c[K+5],s[K+2][N+5],fa[N+K+5];
int find(int x)
{
	return fa[x]==x?x:(fa[x]=find(fa[x]));
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	n=read();
	m=read();
	k=read();
	if(m<=100000||k==0)
	{
		long long ans=1e18;
		for(int i=1;i<=m;i++)
		{
			e[i].u=read();
			e[i].v=read();
			e[i].w=read();
		}
		for(int i=1;i<=k;i++)
		{
			c[i]=read();
			for(int j=1;j<=n;j++)
				s[i][j]=read();
		}
		int w=1<<k;
		for(int i=0;i<w;i++)
		{
			memcpy(t+1,e+1,m*sizeof(edge));
			long long sum=0;
			int ed=m;
			for(int j=1;j<=k;j++)
			{
				if((i>>(j-1))&1)
				{
					sum+=c[j];
					for(int p=1;p<=n;p++)
						t[ed+p]={n+j,p,s[j][p]};
					ed+=n;
				}
			}
			sort(t+1,t+ed+1,[](edge x,edge y){
				return x.w<y.w;
			});
			for(int j=1;j<=n+k;j++)
				fa[j]=j;
	//		printf("%lld ",sum);
			for(int j=1;j<=ed;j++)
			{
				if(find(t[j].u)==find(t[j].v))
					continue;
				sum+=t[j].w;
				fa[find(t[j].u)]=find(t[j].v);
	//			printf("%lld ",sum);
			}
	//		printf("\n");
			ans=min(ans,sum);
		}
		printf("%lld",ans);
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			t[i].u=read();
			t[i].v=read();
			t[i].w=read();
		}
		int ed=m;
		long long sum=0;
		for(int i=1;i<=k;i++)
		{
			c[i]=read();
			sum+=c[i];
			for(int j=1;j<=n;j++)
			{
				t[ed+j].u=n+i;
				t[ed+j].v=j;
				t[ed+j].w=read();
			}
			ed+=n;
		}
		sort(t+1,t+ed+1,[](edge x,edge y){
			return x.w<y.w;
		});
		for(int j=1;j<=n+k;j++)
			fa[j]=j;
//		printf("*");
		for(int j=1;j<=ed;j++)
		{
//			printf("%d\n",j);
			if(find(t[j].u)==find(t[j].v))
				continue;
			sum+=t[j].w;
			fa[find(t[j].u)]=find(t[j].v);
		}
		printf("%lld",sum);
	}
	return 0;
}
