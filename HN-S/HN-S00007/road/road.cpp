#include<bits/stdc++.h>
#define MAXN 1000005
#define ll long long
#define MINN -10000
using namespace std;
ll n,m,k,u,v,w,c[MAXN];
int f[10004][10004],a[10004][10004],r[10004],ans=0;
bool b[10004][10004];
vector <int> e[MAXN];
void check(int x,int y)
{
	cout<<x<<endl;
	for(int i=0;i<e[x].size();i++)
	{
		for(int j=1;j<=k;j++)
		{
			ans=min(ans+e[x][i],ans+r[j]+a[j][i]+a[j][x]);
			b[x][i]=true;
			b[i][x]=true;
			check(i,x);
		}
	}
}
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(f,MAXN,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back((v,w));
		e[v].push_back((u,w));
		if(w<f[u][v])
		{
			f[u][v]=w;
			f[v][u]=w;
		}
	}
	memset(f,MAXN,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][i]=-1;
		b[i][i]=true;
	}
	for(int j=1;j<=k;j++)
	{
		cin>>r[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	check(1,1);
	cout<<ans;
	return 0;
}
