#include <bits/stdc++.h>
using namespace std;
const int N=200;
int n;
int a[N],b[N],c[N];
int dp[N][N][N];
int dfs(int l,int x,int y,int z)
{
	if(dp[l][x][y])return dp[l][x][y];
	if(l>n) return 0;
	int maxn=0;
	if(x<n/2)maxn=max(maxn,dfs(l+1,x+1,y,z)+a[l]);
	if(y<n/2)maxn=max(maxn,dfs(l+1,x,y+1,z)+b[l]);
	if(z<n/2)maxn=max(maxn,dfs(l+1,x,y,z+1)+c[l]);
	dp[l][x][y]=maxn;
	return maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<dfs(1,0,0,0)<<endl;
	}
	return 0;
}
