#include <bits/stdc++.h>
using namespace std;

long long t,n,arr[100001][4]={0},brr[100001]={0},max1=0;
long long dp[100001][4]={0};
bool isok=0;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	std::cin>>t;
	for(int i=1;i<=t;i++)
	{
		std::cin>>n;
		for(int j=1;j<=n;j++)
		{
			std::cin>>arr[j][1]>>arr[j][2]>>arr[j][3];
			if(arr[j][2]!=0||arr[j][3]!=0)
			{
				isok=true;
			}
		}
		if(!isok)//ÌØÐÔA 
		{
			sort(brr+1,brr+1+n);
			for(int j=n;j>n/2;j--)
			{
				max1+=brr[j];
			}
			std::cout<<max1;
		}
		else
		{
			dp[1][1]=arr[1][1];
			dp[1][2]=arr[1][2];
			dp[1][3]=arr[1][3];
			//std::cout<<dp[1][1]<<" "<<dp[1][2]<<" "<<dp[1][3]<<std::endl;
			for(int j=2;j<=n;j++)
			{
				dp[j][1]=max(dp[j-1][2],dp[j-1][3])+arr[j][1];
				dp[j][2]=max(dp[j-1][1],dp[j-1][3])+arr[j][2];
				dp[j][3]=max(dp[j-1][1],dp[j-1][2])+arr[j][3];
				//std::cout<<dp[j][1]<<" "<<dp[j][2]<<" "<<dp[j][3]<<std::endl;
			}
			std::cout<<max(dp[n][3],max(dp[n][1],dp[n][2]))<<std::endl;
		}
	} 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
