#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10100
#define M 4011
#define pii pair<int,int>
#define fi first
#define se second
//	bool Mst;

vector<pii>G[N];
int n,m,k;
int c[50];

int sum;
bool vis[N],inq[N];
int dis[N];
int ans=0;

int f[M][M],a[50][N];
struct node1
{
	int x,y,di;
}d[M*M];
bool cmp(node1 n1,node1 n2)
{
	return n1.di<n2.di;
}

//	bool Med;
void solve2()
{
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		int x,y,w;cin>>x>>y>>w;
		f[x][y]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int kk=1;kk<=k;kk++)
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],a[kk][i]+a[kk][j]+c[kk]);
			}
		}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)d[(i-1)*n+j]={i,j,f[i][j]};
	
	sort(d+1,d+n*n+1,cmp);
	
	int ans=0;
	for(int i=1;i<=n*n;i++)if(d[i].x!=d[i].y&&(!vis[d[i].x]||!vis[d[i].y]))
	{
		ans+=d[i].di;
		vis[d[i].x]=vis[d[i].y]=1;
	}
	
	cout<<ans;
}

signed main()
{
//	printf("%.2lf",1.0*(&Mst-&Med)/1024/1024);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
//	freopen("road2.in","r",stdin);
	
	cin>>n>>m>>k;
	solve2();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
//≤ªœ‡»œ
