#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int u[N],v[N],w[N];
int a[1005][1005],c[N];
bool vis[1005][1005],pd[N];
int s[1005][1005];
int num=0;
int ans=0;	
int n,m,k;
int t=INT_MAX;
void dfs(int i)
{ 
    if(num==n-1)
    {
    	t=min(t,ans);
    	return;
	}
	for(int j=1;j<=n;j++)
	{
		if(i==j) continue;
		if(vis[i][j]==1&&pd[j]!=1)
		{
			ans+=s[i][j];
			num++;
			pd[j]=1;
			dfs(j);
			num--;
			ans-=s[i][j];
			pd[j]=0;
		}
	}
   return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
	   cin>>u[i]>>v[i]>>w[i];
	   vis[u[i]][v[i]]=vis[v[i]][u[i]]=1;
	   s[u[i]][v[i]]=s[v[i]][u[i]]=w[i];	
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=0;i<=n;i++)
		{
			if(i==0) 
			{
				cin>>c[j];
				continue;
			}
			cin>>a[j][i];
		}
	}
	dfs(1);
	cout<<t<<endl;
	return 0;
}
