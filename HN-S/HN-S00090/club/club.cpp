#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,dp[2][N][N][N];
void work()
{
	memset(dp,0,sizeof(dp));
	cin>>n;
	int flag=1,ans=0;
	for(int i=1,a,b,c;i<=n;i++)
	{
		cin>>a>>b>>c;
		for(int x=0;x<=n/2;x++)
			for(int y=0;y<=n/2;y++)
				for(int z=0;z<=n/2;z++)
				{
					if(x!=0)
						dp[flag][x][y][z]=max(dp[flag][x][y][z],dp[flag^1][x-1][y][z]+a);
					if(y!=0)
						dp[flag][x][y][z]=max(dp[flag][x][y][z],dp[flag^1][x][y-1][z]+b);
					if(z!=0)
						dp[flag][x][y][z]=max(dp[flag][x][y][z],dp[flag^1][x][y][z-1]+c);
					ans=max(ans,dp[flag][x][y][z]);
				}
		flag^=1;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		work();
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

this CSP I maybe only 195pts but I'm grade 8,I'm so vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable,vegetable
My OI maybe over after this CSP TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT TT
*/
