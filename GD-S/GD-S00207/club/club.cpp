#include<bits/stdc++.h>
using namespace std;
int dp[506][506][506];
int T,n,maxn;
struct fw{
	int a,b,c;
}f[100005];
int My_min(int x,int y)
{
	return x<y?x:y; 
}
int My_max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		maxn=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			cin>>f[i].a>>f[i].b >>f[i].c ;
		}
		for(int i=1;i<=n;i++)
		{
			for(int x=0;x<=My_min(i,n/2);x++)
			{
				for(int y=0;y<=My_min(i,n/2);y++)
				{
					int z=i-x-y;
					if(z<0||z>n/2) continue;
					if(x)dp[x][y][z]=My_max(dp[x][y][z],dp[x-1][y][z]+f[i].a);
					if(y)dp[x][y][z]=My_max(dp[x][y][z],dp[x][y-1][z]+f[i].b);
					if(z)dp[x][y][z]=My_max(dp[x][y][z],dp[x][y][z-1]+f[i].c);
					maxn=My_max(maxn,dp[x][y][z]);
				}
			}
		}cout<<maxn<<endl;
	}
	
	return 0;
} 
