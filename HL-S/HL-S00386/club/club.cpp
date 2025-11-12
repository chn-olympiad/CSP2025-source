#include<bits/stdc++.h>
using namespace std;
int student[100010][4];
int club[4];
struct sit
{
	int interest,people;
}dp[20][20000][10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>student[i][1]>>student[i][2]>>student[i][3];
		}
		dp[1][1][1].people=1,dp[1][2][2].people=1,dp[1][3][3].people=1;
		dp[1][1][1].interest=student[1][1],dp[1][2][2].interest=student[1][2],dp[1][3][3].interest=student[1][3];
		int ans=dp[1][1][1].interest;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=pow(3,i);j+=3)
			{
				if(dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people<(n/2))
				{
					dp[i][j][1].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
					dp[i][j][2].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
					dp[i][j][3].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
					dp[i][j][1].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
					dp[i][j][2].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
					dp[i][j][3].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
					ans=max(ans,dp[i][j][1].interest);
				}
				else if(dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people<(n/2))
				{
					if(student[i][2]>student[i][3])
					{
						dp[i][j][1].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
						dp[i][j][2].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
						dp[i][j][3].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
						dp[i][j][1].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
						dp[i][j][2].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
						dp[i][j][3].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
						ans=max(ans,dp[i][j][2].interest);
					}
					else
					{
						dp[i][j][1].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
						dp[i][j][2].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
						dp[i][j][3].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
						dp[i][j][1].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
						dp[i][j][2].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
						dp[i][j][3].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
						ans=max(ans,dp[i][j][3].interest);
					}
				}

				if(dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people<(n/2))
				{
					dp[i][j][2].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
					dp[i][j][1].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
					dp[i][j][3].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
					dp[i][j][2].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
					dp[i][j][1].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
					dp[i][j][3].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
					ans=max(ans,dp[i][j+1][2].interest);
				}
				else if(dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people<(n/2))
				{
					if(student[i][1]>student[i][3])
					{
						dp[i][j][2].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
						dp[i][j][1].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
						dp[i][j][3].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
						dp[i][j][2].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
						dp[i][j][1].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
						dp[i][j][3].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
						ans=max(ans,dp[i][j+1][2].interest);
					}
					else
					{
						dp[i][j][1].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
						dp[i][j][2].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
						dp[i][j][3].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
						dp[i][j][1].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
						dp[i][j][2].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
						dp[i][j][3].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
						ans=max(ans,dp[i][j+1][3].interest);
					}
				}

				if(dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people<(n/2))
				{
					dp[i][j][3].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
					dp[i][j][1].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
					dp[i][j][2].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
					dp[i][j][3].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
					dp[i][j][1].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
					dp[i][j][2].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
					ans=max(ans,dp[i][j+2][1].interest);
				}
				else if(dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people<(n/2))
				{
					if(student[i][2]>student[i][1])
					{
						dp[i][j][2].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
						dp[i][j][1].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
						dp[i][j][3].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
						dp[i][j][1].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
						dp[i][j][2].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
						dp[i][j][3].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].people;
						ans=max(ans,dp[i][j+2][2].interest);
					}
					else
					{
						dp[i][j][3].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][3].interest;
						dp[i][j][2].interest=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].interest;
						dp[i][j][1].interest=student[i][1]+dp[i-1][((j%3==0)?j/3:(j/3+1))][1].interest;
						dp[i][j][1].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
						dp[i][j][2].people=dp[i-1][((j%3==0)?j/3:(j/3+1))][2].people;
						dp[i][j][1].people=1+dp[i-1][((j%3==0)?j/3:(j/3+1))][1].people;
						ans=max(ans,dp[i][j+2][1].interest);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
