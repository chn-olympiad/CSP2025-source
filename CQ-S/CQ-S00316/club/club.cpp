#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
int dp[N][N][N],a[N][N];
int main()
{
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);	
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector <vector <int> > a(n,vector<int> (3));
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
	}
	int k=(n+2)/3;
	dp[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int x=k;x>=0;x--)
		{
			for(int y=k;y>=0;y--)
			{
				for(int z=k;z>=0;z--)		
				{
					if(dp[x][y][z]=INT_MIN) continue;
					if(x<k) dp[x][y+1][z]=max(dp[x][y+1][z],dp[x][y][z]+a[i][1]);
					if(z<k) dp[x][y][z+1]=max(dp[x][y][z+1],dp[x][y][z]+a[i][2]);
				}
			}
		}
	}
	int ans=0;
	for(int x=0;x<=k;x++)
	{
		for(int y=0;y<=k;y++)
		{
			for(int z=0;z<=k;z++)
			{
				if(x+y+z==n)
				{
					ans=max(ans,dp[x][y][z]);
				}
			}
		}
	}
	cout<<ans<<endl;
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
