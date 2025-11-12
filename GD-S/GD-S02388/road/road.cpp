#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9+10;
struct edge
{
	int t,nxt,len;
}road[1000050];
int n,m,k;
int a[10050][10050];
int ans;
int cnt,head[10050];
void build(int u,int v,int length)
{
	cnt++;
	road[cnt].t=v;
	road[cnt].nxt=head[u];
	head[u]=cnt;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		a[i][j]=inf;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		cin>>u>>v>>l;
		a[u][v]=min(a[u][v],l);
	}
	if(k==0)
	{
		
	}
	for(int i=1;i<=k;i++)
	{
		int len;
		cin>>len;
		for(int j=1;j<=n;j++)
		{
			int lenk;
			cin>>lenk;
			a[j][n+i]=len+lenk;
			a[n+i][j]=len+lenk;
		}
	}
	cout<<ans;
	return 0;
}

