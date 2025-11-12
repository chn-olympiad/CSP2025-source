#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
const int INF=0x3f3f3f3f;
struct node
{
	int v,w;
};
int n,m,k,a[N][N],dist[N],ans;
bool f[N];
int prim()
{
	memset(f,0,sizeof(f));
	memset(dist,INF,sizeof(dist));
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
		int minn=INF,x=0;
		for(int j=1;j<=n;j++)if((!f[j])&&(dist[j]<minn||!x))x=j,minn=dist[j];
		for(int j=1;j<=n;j++)dist[j]=min(dist[j],dist[x]+a[x][j]);
		f[x]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dist[i]==INF)return INF;
		ans+=dist[i];
	}
	return ans;
}
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.put","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
   cin>>n>>m>>k;
   memset(a,INF,sizeof(a));
   for(int i=1;i<=n;i++)a[i][i]=0;
   for(int i=1;i<=m;i++)
   {
	   int u,v,w;
	   cin>>u>>v>>w;
	   a[u][v]=a[v][u]=w;
   }
   ans=prim();
   for(int i=1;i<=k;i++)
   {
	   int p;
	   cin>>p;
	   int s[11];
	   for(int j=1;j<=n;j++)
	   {
		   cin>>s[j];
		   if(a[i][j]>s[j])swap(a[i][j],s[j]);
		   else s[j]=0;
	   }
	   ans=min(ans,p+prim());
	   for(int j=1;j<=n;j++)if(!s[j])a[i][j]=s[j];
   }
   cout<<ans;
   return 0;
}
