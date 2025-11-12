#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][3],c[N][3][3],f[N][3];
int n,ans;
int vis[3];
void dfs(int x,int sum)
{
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(vis[0]<n/2)
	{
		vis[0]++;
		dfs(x+1,sum+a[x][0]);
		vis[0]--;
	}
	if(vis[1]<n/2)
	{
		vis[1]++;
		dfs(x+1,sum+a[x][1]);
		vis[1]--;
	}
	if(vis[2]<n/2)
	{
		vis[2]++;
		dfs(x+1,sum+a[x][2]);
		vis[2]--;
	}
}
void sol()
{
	memset(f,0,sizeof f);
	memset(c,0,sizeof c);
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=0;j<=2;j++) cin>>a[i][j];
	if(n<=10)
	{
		memset(vis,0,sizeof vis);
		ans=0;
		dfs(1,0);
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		{
			if(c[i-1][0][j]<n/2||j!=0)
			{
				if(f[i-1][0]+a[i][j]>=f[i][j])
				{
					f[i][j]=f[i-1][0]+a[i][j];
					for(int k=0;k<=2;k++) c[i][j][k]=c[i-1][0][k];
					c[i][j][j]++;
				}
			}
			if(c[i-1][1][j]<n/2||j!=1)
			{
				if(f[i-1][1]+a[i][j]>=f[i][j])
				{
					f[i][j]=f[i-1][1]+a[i][j];
					for(int k=0;k<=2;k++) c[i][j][k]=c[i-1][1][k];
					c[i][j][j]++;
				}
			}
			if(c[i-1][2][j]<n/2||j!=2)
			{
				if(f[i-1][2]+a[i][j]>=f[i][j])
				{
					f[i][j]=f[i-1][2]+a[i][j];
					for(int k=0;k<=2;k++) c[i][j][k]=c[i-1][2][k];
					c[i][j][j]++;
				}
			}
		}
	}
	cout<<max({f[n][0],f[n][1],f[n][2]})<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--) sol();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
