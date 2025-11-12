#include<bits/stdc++.h>
using namespace std;
#define cin std::cin
#define cout std::cout
long long n,m,k,ans=0;
long long costm[1000005][1000005],costk[15],costkn[15][10005];
bool tong[1000005][1000005];
void tlu(int x,int y)
{
	tong[x][y]=1;
	tong[y][x]=1;
	for(int i=1;i<=n;i++)
	{
		if(tong[x][i]||tong[i][x]) 
		{
			tong[y][i]=1;
			tong[i][y]=1;
		}
		if(tong[y][i]||tong[i][y])
		{
			tong[x][i]=1;
			tong[i][x]=1;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long x,y;
		cin>>x>>y;
		cin>>costm[x][y];
		ans+=costm[x][y];
	}
	for(int i=1;i<=k;i++) 
	{
		cin>>costk[i];
		for(int j=1;j<=n;j++) cin>>costkn[i][j];
	}
	cout<<ans<<endl;
	return 0;
}