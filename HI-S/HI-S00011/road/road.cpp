#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m,k,s;
int p[N/100],c[15],a[15][N/100];
int f[15][N/100];
bool b[N/100];
struct{
	int from,to,w,next;
}rode[N*2+N/100];
void walk(int x)
{
	for(int i=p[x];i!=0;i=rode[i].next)
	{
		int from=rode[i].from,to=rode[i].to;
		if(b[to]==false)
		{
			b[to]=true;
			if(rode[i].w<f[0][to])
			{
				f[0][to]=rode[i].w;
				walk(to);
			}
			for(int j=1;j<=k;j++)
			{
				f[k][to]=min(f[k][to],a[k][from]+a[k][to]);
			}
			b[to]=false;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		rode[++s]={u,v,w,p[u]};
		p[u]=s;
		rode[++s]={v,u,w,p[v]};
		p[v]=s;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		rode[++s]={0,i,0,p[0]};
		p[0]=s;
	}
	walk(0);
	memset(f,0x3f,sizeof(f));
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=f[0][i];
	}
	for(int i=1;i<=k;i++)
	{
		long long sum=c[i];
		for(int j=1;j<=n;j++)
		{
			sum+=min(f[i-1][j],f[i][j]);
		}
		if(sum<=ans)
		{
			ans=sum;
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i-1][j]);
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=f[i-1][j];
			}
		}
	}
	cout<<ans;
	return 0;
} 
