#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=INT_MAX,cnt;
int a[5000][5000];
bool b[5000][5000],c[5000][5000];
void pd(int x,int y)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j]==1&&c[i][j]==0)
			{
				cnt++;
				c[i][j]=1;
				pd(i,j);
			}
}
void dfs(int i,int j,int money)
{
	if(a[i][j]==-1)
		return;
	cnt=0;
	pd(i,j);
	
	if(cnt==n)
	{
		ans=min(ans,money);
		return;
	}
	if(i>n||j>n)
		return;
	b[i][j]=1;
	b[j][i]=1;
	if(a[i+1][j]!=-1)
		dfs(i+1,j,money+a[i][j]);
	if(a[i][j+1]!=-1)
		dfs(i,j+1,money+a[i][j]);
	if(a[i+1][j+1]!=-1)
		dfs(i+1,j+1,money+a[i][j]);
	b[i][j]=0;
	b[j][i]=0;
	if(a[i+1][j]!=-1)
		dfs(i+1,j,money);
	if(a[i][j+1]!=-1)
		dfs(i,j+1,money);
	if(a[i+1][j+1]!=-1)
		dfs(i+1,j+1,money);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	int x,y,q;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>q;
		a[x][y]=a[y][x]=q;
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
