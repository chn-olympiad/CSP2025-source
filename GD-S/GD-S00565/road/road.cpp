#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+30;
ll n,m,k,a[maxn][maxn],c[maxn],u,v,w,vis[maxn],dis[maxn],ans,kk[maxn];
void prime()
{
	for(int i=1;i<=n;i++) dis[i]=1141541919810;
	dis[1]=0;
	int uv=0;
	while(1)
	{
		uv++;
		ll maxn_=1145141919810,u=0;
		for(int i=1;i<=n;i++)	
			if(!vis[i]&&dis[i]<maxn_)
				maxn_=dis[i],u=i;
		vis[u]=1;
//		cout<<uv<<" ";
		if(u==0) break;
		for(int i=1;i<=n;i++)
		{
			dis[i]=min(dis[i],a[i][u]+maxn_);
//			cout<<dis[i]<<" ";
		}
		ans+=maxn_;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool o1=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)a[i][j]=1145141919810;
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=w;a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) o1=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i+n][j];
			a[j][i+n]=a[i+n][j];
			if(a[i+n][j]==0) 
			{
				kk[i]=j;
			}
		}
	}
	if(k==0)
	{
		prime();
		cout<<ans<<endl;
		return 0;
	}
	if(o1==0)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
			{
				a[kk[i]][j]=a[j][kk[i]]=min(a[j][kk[i]],a[j][i+n]);
			}
		prime();
		cout<<ans<<endl;
	}
	return 0;
}
