//GZ-S00055 贵阳市第三实验中学 刘明远 
#include<bits/stdc++.h>
using namespace std;

long long dp[2][101][101][101];
int per[205][3];

int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&per[i][1],&per[i][2],&per[i][3]);
		}
		long long nw=1,la=0,ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n/2&&j<=i;j++)
			{
				for(int k=max(0,i-j-n/2);k<=i-j&&k<=n/2;k++)
				{
					int l=i-(j+k);
					int t1=(j>0?dp[la][j-1][k][l]+per[i][1]:0LL);
					int t2=(k>0?dp[la][j][k-1][l]+per[i][2]:0LL);
					int t3=(l>0?dp[la][j][k][l-1]+per[i][3]:0LL);
					dp[nw][j][k][l]=max(t1,max(t2,t3));
					if(i==n)
						ans=max(ans,dp[nw][j][k][l]);
				}
			}
			swap(nw,la);
		}
		printf("%lld\n",ans);
	}
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
