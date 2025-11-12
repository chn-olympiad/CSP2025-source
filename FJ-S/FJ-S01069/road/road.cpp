#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+1e1,M=1e7+1e3;
int n,m,k,ans,cnt,a[N],c[N],fa[N<<4],f[N][N];
struct sb
{
	int x,y,z;
}e[M];
bool cmp(sb x,sb y)
{
	return x.z<y.z;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	if(!k)
	{
		for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].z;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		int p=0;
		for(int i=1;i<=m&&p<n-1;i++)
		{
			int u=find(e[i].x),v=find(e[i].y);
			if(u!=v)
			{
				fa[u]=v; p++;
				ans+=e[i].z;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		f[i][j]=1e16;
	for(int i=1,x,y,z;i<=m;i++) 
	{
		cin>>x>>y>>z;
		f[x][y]=f[y][x]=min(f[x][y],z);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			for(int k=1;k<j;k++)
			f[j][k]=f[k][j]=min(f[j][k],c[i]+a[j]+a[k]);
		}
	}
	for(int i=1;i<=n;fa[i]=i,i++)
		for(int j=1;j<i;j++)
			if(f[i][j]<1e16)
			e[++cnt]=(sb){i,j,f[i][j]};
	sort(e+1,e+cnt+1,cmp);
	int p=0;
	for(int i=1;i<=cnt&&p<n-1;i++)
	{
		int u=find(e[i].x),v=find(e[i].y);
		if(u!=v)
		{
			fa[u]=v; p++;
			ans+=e[i].z;
		}
	}
	cout<<ans;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4