#include<bits/stdc++.h>
#define ll long long
#define N (int)1e4+10
using namespace std;

ll n,m,k;
ll chse;
struct edge
{
	ll from,to,next,v;
}e[1000010*5];
ll head[N],fa[N],tot,vis[N],c[N],a[N][N],got[N][N];
ll dp[1<<11][51];
void add(int x,int y,int z)
{
	e[++tot]=(edge){x,y,head[x],z};
	head[x]=tot;
}
bool gz(edge x,edge y)
{
	return x.v<y.v;
}
ll find(ll x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
ll kru()
{
	for(ll i=1; i<=n; i++)
		fa[i]=i;
	sort(e+1,e+tot+1,gz);
	int num=0,ans=0;
	for(ll i=1; ; i+=2)
	{
		ll u=e[i].from,v=e[i].to,uu=find(u),vv=find(v);
		if(uu==vv)
			continue;
		num++;
		fa[v]=u,fa[vv]=uu;
		ans+=e[i].v;
		if(num==n-1)
			return ans;
	}
}
ll dfs(ll x)
{
	if(x>k) return kru();
	if(dp[chse][x]) return dp[chse][x];
	ll s=dfs(x+1);
	bool flag=false;
	for(ll i=1; i<n; i++)
		for(ll j=i+1; j<=n; j++)
		{
			add(i,j,a[x][i]+a[x][j]);
			add(j,i,a[x][i]+a[x][j]);
			if(got[i][j]>a[x][i]+a[x][j])
				flag=true,got[i][j]=got[j][i]=a[x][i]+a[x][j];
		}
	chse|=1<<(x-1);
	if(flag)
		s=min(s,dfs(x+1)+c[x]);
	tot-=n*(n-1)/2;
	chse-=1<<(x-1);
	return dp[chse][x]=s;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	memset(got,0x3f,sizeof got);
	for(ll i=1,x,y,z; i<=m; i++)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	bool V=true;
	for(int i=1; i<=k; i++)
	{
		scanf("%lld",c+i);
		if(c[i]!=0)
			V=false;
		for(int j=1; j<=n; j++)
			scanf("%lld",&a[i][j]);
	}
	if(k==0)
	{
		printf("%lld",kru());
		return 0;
	}
	if(V)
	{
		for(int i=1; i<=k; i++)
			for(int j=1; j<n; j++)
				for(int k=j+1; k<=n; k++)
				{
					
					add(j,k,a[i][j]+a[i][k]);
					add(k,j,a[i][j]+a[i][k]);
					/*if(i==2&&j==1&&k==3)
						printf("A%lld %lld ",a[i][j]+a[i][k],tot);*/
				}
		printf("%lld\n",kru());
		/*for(int i=1; i<=tot; i+=2)
			printf("%lld %lld %lld\n",e[i].from,e[i].to,e[i].v);*/
		return 0;
	}
	printf("%lld",dfs(1));
	return 0;
}

