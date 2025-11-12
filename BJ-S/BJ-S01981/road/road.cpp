#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
//多测要清空！！！！！！！！！！
struct node
{
	int cnt1,cnt2,cnt3,val;
}dp[N][5];
int a[N][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n;
		m=n/2;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		dp[1][1].val=a[1][1],dp[1][2].val=a[1][2],dp[1][3].val=a[1][3];
		dp[1][1].cnt1=1,dp[1][2].cnt2=1,dp[1][3].cnt3=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=3;j++)//i选什么
			{
				int maxx=-2e9,id=0;
				for(int k=1;k<=3;k++)//上一个选什么
				{
					if(j==1&&dp[i-1][k].cnt1+1>m) continue;
					if(j==2&&dp[i-1][k].cnt2+1>m) continue;
					if(j==3&&dp[i-1][k].cnt3+1>m) continue;
					if(dp[i-1][k].val+a[i][j]>maxx) maxx=dp[i-1][k].val+a[i][j],id=k;
				}
				dp[i][j].val=maxx;
				dp[i][j].cnt1=dp[i][id].cnt1,dp[i][j].cnt2=dp[i][id].cnt2,dp[i][j].cnt3=dp[i][id].cnt3;
				if(j==1) dp[i][j].cnt1++;
				if(j==2) dp[i][j].cnt2++;
				if(j==3) dp[i][j].cnt3++;
				maxx=-2e9,id=0;
			}
		}
		cout<<max(dp[n][1].val,max(dp[n][2].val,dp[n][3].val))<<"\n";
	}
	
	return 0;
}
