#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m,k;
int u,v,w;
int c[11],a;
int ma[1010][1010]; 
int vis[1010][1010]; 
int ans[10050];
int main(int argc, char** argv)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=1010;i++)
		for(int j=1;j<=1010;j++)
			ma[i][j]=1e9;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		ma[u][v]=ma[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a;
			ma[i+n][j]=ma[j][i+n]=a;
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		int l=1;
		for(int j=i;j<=n+k;j++)
		{
			if((ma[i][j]==1e9 && ma[i][j-1]==1e9) || vis[i][j]==1 || vis[j][i]==1)
			{
				continue;
			}
			if(i>n && j>n)
			{
				ans[l]+=min(ma[i][j]+c[j-n],ma[i][j-1]+c[j-n]);
			}
			else if(i>n && j<=n)
			{
				ans[l]+=min(ma[i][j]+c[j-n],ma[i][j-1]);
			}
			else if(i<=n && j>n)
			{
				ans[l]+=min(ma[i][j],ma[i][j-1]+c[j-n]);
			}
			else
			{
				ans[l]+=min(ma[i][j],ma[i][j-1]);
			}
			vis[i][j-1]==1;
		}
	}
	cout<<ans[1];
	return 0;
}