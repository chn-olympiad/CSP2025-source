#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200000][5];
struct node{
	long long z,a,b,c;
}dp[200000][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cin>>n;
		long long k=n/2,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		dp[1][1].z=a[1][1];
		dp[1][2].z=a[1][2];
		dp[1][3].z=a[1][3];
		dp[1][1].a=1;
		dp[1][2].b=1;
		dp[1][3].c=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(j==1&&dp[i-1][j].a<k)
				{
					if(dp[i-1][1].z>=dp[i-1][2].z&&dp[i-1][1].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][1].z+a[i][j];
						dp[i][j].a=dp[i-1][1].a+1;
						dp[i][j].b=dp[i-1][1].b;
						dp[i][j].c=dp[i-1][1].c;
					}
					if(dp[i-1][2].z>=dp[i-1][1].z&&dp[i-1][2].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][2].z+a[i][j];
						dp[i][j].a=dp[i-1][2].a+1;
						dp[i][j].b=dp[i-1][2].b;
						dp[i][j].c=dp[i-1][2].c;						
					}
					if(dp[i-1][3].z>=dp[i-1][1].z&&dp[i-1][3].z>=dp[i-1][2].z){
						dp[i][j].z=dp[i-1][3].z+a[i][j];
						dp[i][j].a=dp[i-1][3].a+1;
						dp[i][j].b=dp[i-1][3].b;
						dp[i][j].c=dp[i-1][3].c;							
					}
				}
				else if(j==1&&dp[i-1][j].a>=k)
				{
					if(dp[i-1][2].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][2].z+a[i][j];
						dp[i][j].a=dp[i-1][2].a+1;
						dp[i][j].b=dp[i-1][2].b;
						dp[i][j].c=dp[i-1][2].c;						
					}
					if(dp[i-1][3].z>=dp[i-1][2].z){
						dp[i][j].z=dp[i-1][3].z+a[i][j];
						dp[i][j].a=dp[i-1][3].a+1;
						dp[i][j].b=dp[i-1][3].b;
						dp[i][j].c=dp[i-1][3].c;							
					}					
				}
				
				
				else if(j==2&&dp[i-1][j].b<k)
				{
					if(dp[i-1][1].z>=dp[i-1][2].z&&dp[i-1][1].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][1].z+a[i][j];
						dp[i][j].a=dp[i-1][1].a;
						dp[i][j].b=dp[i-1][1].b+1;
						dp[i][j].c=dp[i-1][1].c;
					}
					if(dp[i-1][2].z>=dp[i-1][1].z&&dp[i-1][2].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][2].z+a[i][j];
						dp[i][j].a=dp[i-1][2].a;
						dp[i][j].b=dp[i-1][2].b+1;
						dp[i][j].c=dp[i-1][2].c;						
					}
					if(dp[i-1][3].z>=dp[i-1][1].z&&dp[i-1][3].z>=dp[i-1][2].z){
						dp[i][j].z=dp[i-1][3].z+a[i][j];
						dp[i][j].a=dp[i-1][3].a;
						dp[i][j].b=dp[i-1][3].b+1;
						dp[i][j].c=dp[i-1][3].c;							
					}
				}
				else if(j==2&&dp[i-1][j].b>=k)
				{
					if(dp[i-1][1].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][1].z+a[i][j];
						dp[i][j].a=dp[i-1][1].a;
						dp[i][j].b=dp[i-1][1].b+1;
						dp[i][j].c=dp[i-1][1].c;						
					}
					if(dp[i-1][3].z>=dp[i-1][1].z){
						dp[i][j].z=dp[i-1][3].z+a[i][j];
						dp[i][j].a=dp[i-1][3].a;
						dp[i][j].b=dp[i-1][3].b+1;
						dp[i][j].c=dp[i-1][3].c;							
					}					
				}
				
				
				
				else if(j==3&&dp[i-1][j].c<k)
				{
					if(dp[i-1][1].z>=dp[i-1][2].z&&dp[i-1][1].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][1].z+a[i][j];
						dp[i][j].a=dp[i-1][1].a;
						dp[i][j].b=dp[i-1][1].b;
						dp[i][j].c=dp[i-1][1].c+1;
					}
					if(dp[i-1][2].z>=dp[i-1][1].z&&dp[i-1][2].z>=dp[i-1][3].z)
					{
						dp[i][j].z=dp[i-1][2].z+a[i][j];
						dp[i][j].a=dp[i-1][2].a;
						dp[i][j].b=dp[i-1][2].b;
						dp[i][j].c=dp[i-1][2].c+1;						
					}
					if(dp[i-1][3].z>=dp[i-1][1].z&&dp[i-1][3].z>=dp[i-1][2].z){
						dp[i][j].z=dp[i-1][3].z+a[i][j];
						dp[i][j].a=dp[i-1][3].a;
						dp[i][j].b=dp[i-1][3].b;
						dp[i][j].c=dp[i-1][3].c+1;							
					}
				}
				else if(j==3&&dp[i-1][j].c>=k)
				{
					if(dp[i-1][1].z>=dp[i-1][2].z)
					{
						dp[i][j].z=dp[i-1][1].z+a[i][j];
						dp[i][j].a=dp[i-1][1].a;
						dp[i][j].b=dp[i-1][1].b;
						dp[i][j].c=dp[i-1][1].c+1;						
					}
					if(dp[i-1][2].z>=dp[i-1][1].z){
						dp[i][j].z=dp[i-1][2].z+a[i][j];
						dp[i][j].a=dp[i-1][2].a;
						dp[i][j].b=dp[i-1][2].b;
						dp[i][j].c=dp[i-1][2].c+1;							
					}					
				}
				
				
				
				
				
			}
		}
		for(int i=1;i<=3;i++)
		{
			ans=max(dp[n][i].z,ans);
		}
		cout<<ans<<endl;		
	}
	
	return 0;
} 

