#include<bits/stdc++.h>
using namespace std;

const int K=11;
const int N=10005;
const int M=1000005;
#define LL long long

int n,m,k;
struct node
{
	int u,v,w;
	bool operator <(node ee)
	{
		return w<ee.w;
	}
}e[M+N*K],e2[M+N*K];
int m2;
int cost[K],a[K][N],must[K];
LL ans;
LL dp[1<<K];
bool use[1<<K];

int f[N+K];
int out_w[N],out_v[N];
int find(int u)
{
	if (f[u]==u)return u;
	return (f[u]=find(f[u]));
}
LL get()
{
	LL res=0;
	for (int i=1;i<=n;i++)
		f[i]=i;
	while (m2>0)
	{
		// printf("m2:%d\n",m2);
		for (int i=1;i<=n;i++)
		{
			out_v[i]=0;
			out_w[i]=1e9+1;
		}
		for (int i=1;i<=m2;i++)
		{
			// e2[i].u=find(e2[i].u);
			// e2[i].v=find(e2[i].v);
			assert(f[e2[i].u]==e2[i].u);
			assert(f[e2[i].v]==e2[i].v);
			if (e2[i].w<out_w[e2[i].u])
			{
				out_v[e2[i].u]=e2[i].v;
				out_w[e2[i].u]=e2[i].w;
			}
			if (e2[i].w<out_w[e2[i].v])
			{
				out_v[e2[i].v]=e2[i].u;
				out_w[e2[i].v]=e2[i].w;
			}
		}
		// int root=0,merge=0;
		for (int i=1;i<=n;i++)
		{
			if (f[i]==i)
			{
				// root++;
				// printf("%d %d %d\n",i,out_v[i],out_w[i]);
				assert(out_v[i]);
				out_v[i]=find(out_v[i]);
				if (i!=out_v[i])
				{
					// merge++;
					f[i]=out_v[i];
					res+=out_w[i];
				}
			}
		}
		// printf("\nroot:%d,merge:%d\n",root,merge);
		for (int i=1;i<=m2;i++)
		{
			e2[i].u=find(e2[i].u);
			e2[i].v=find(e2[i].v);
			if(e2[i].u==e2[i].v)
			{
				swap(e2[i],e2[m2]);
				i--;
				m2--;
			}
		}
	}
	return res;
}
bool check_cost()
{
	for (int i=1;i<=k;i++)
	{
		if (cost[i]) return 0;
	}
	return 1;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for (int i=1;i<=m;i++)
	{
		if(e[i].u==e[i].v)
		{
			swap(e[i],e[m]);
			i--,m--;
		}
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&cost[i]);
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if (check_cost())
	{
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=n;j++)
			{
				m++;
				e[m].u=n+i,e[m].v=j,e[m].w=a[i][j];
			}
		}
		for (int i=1;i<=n+k;i++)
			f[i]=i;
		sort(e+1,e+m+1);
		for (int i=1;i<=m;i++)
		{
			e[i].u=find(e[i].u);
			e[i].v=find(e[i].v);
			if (e[i].u!=e[i].v)
			{
				f[e[i].u]=e[i].v;
				ans+=e[i].w;
		// printf("%lld\n",ans);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for (int i=1;i<=k;i++)
	{
		must[i]=1;
		for (int j=2;j<=n;j++)
		{
			if (a[i][j]<a[i][must[i]])must[i]=j;
		}
	}
	ans=1000000000ll*N;
	for (int i=0;i<(1<<k);i++)
	{
		use[i]=1;
		for (int j=1;j<=k;j++)
		{
			if ((1<<(j-1))&i)
			{
				if (!use[i-(1<<(j-1))])
				{
					use[i]=0;
					break;
				}
			}
		}
		if (!use[i]) continue;
		for (int j=1;j<=m;j++)
		{
			e2[j]=e[j];
		}
		m2=m;
		int base=0;
		for (int j=1;j<=k;j++)
		{
			if ((1<<(j-1))&i)
			{
				base+=cost[j]+a[j][must[j]];
				for (int l=1;l<=n;l++)
				{
					if (l!=must[j])
					{
						e2[++m2].u=must[j];
						e2[m2].v=l;
						e2[m2].w=a[j][l];	
					}
				}
			}
		}
		dp[i]=base+get();
		for (int j=1;j<=k;j++)
		{
			if ((1<<(j-1))&i)
			{
				if (dp[i]>=dp[i-(1<<(j-1))])
				{
					use[i]=0;
					break;
				}
			}
		}
		// printf("dp[%d]=%lld\n",i,dp[i]);
		ans=min(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}