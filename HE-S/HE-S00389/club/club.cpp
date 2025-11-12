#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];
int c[100005];
bool vis[100005];
int dp[100005];
int size=0;
int c_a,c_b,c_c;
int max_index;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		int n;
		c_a=0;
		c_b=0;
		c_c=0;
		cin>>n;
		size=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i]; 		
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				int x=dp[i];
				if(c_a<size)
				{
					
					dp[i]=max(dp[i],dp[i-1]+a[i]);
					if(x<dp[i])
					{
						max_index=1;	
					}
				}
				if(c_b<size)
				{
					dp[i]=max(dp[i],dp[i-1]+b[i]);
					if(x<dp[i])
					{
						max_index=2;
					}
				}
				if(c_c<size)
				{
					dp[i]=max(dp[i],dp[i-1]+c[i]);
					if(x<dp[i])
					{
						max_index=3;
					}
				}
  				vis[i]==1;	
				switch(max_index)
				{
					case 1:{
						c_a++;
						break;
					}
					case 2:{
						c_b++;
						break;
					}
					case 3:{
						c_c++;
						break;
					}
				}
			}
		}
		
		cout<<dp[n];
	}
	return 0;
}
