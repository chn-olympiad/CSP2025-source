#include <bits/stdc++.h>

using namespace std;

const int N=1e4+10,M=2e6+10;
struct Node
{
	int x,y,z;
}p[M],w[M];
int vis[N],n,m,k,a[20][N],f[N],tot;
long long mn=1e18;

bool cmp(Node a,Node b)
{
	return a.z<b.z;
}

int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void dfs(int nw)
{
	if(nw==k+1) 
	{
		long long res=0;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=k;i++) if(vis[i]==1) res+=1ll*a[i][0];
		for(int i=1;i<=tot;i++) 
		{
			if(w[i].x>n&&vis[w[i].x-n]==0) continue ;
			if(find(w[i].x)!=find(w[i].y))
			{
				f[find(w[i].x)]=find(w[i].y);
				res+=1ll*w[i].z;
			}
			if(res>mn) return ;
		}
		mn=min(mn,res);
		return ;
	}
	vis[nw]=1,dfs(nw+1);
	vis[nw]=0,dfs(nw+1);
	return ;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
	sort(p+1,p+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) 
	{
		if(find(p[i].x)!=find(p[i].y)) 
		{
			f[find(p[i].x)]=find(p[i].y);
			w[++tot]=p[i]; 
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i][0]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			w[++tot]={i+n,j,a[i][j]};
		}
	}
	sort(w+1,w+1+tot,cmp);
	dfs(1);
	printf("%lld",mn);
	return 0;
} 