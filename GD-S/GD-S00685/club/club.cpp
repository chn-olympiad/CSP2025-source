#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
long long a[100010][4];
long long dp[210][110][110];
void solve(long long i,long long j,long long k)
{
	if(i==j) dp[i][j][k]=dp[i-1][j-1][k]+a[i][1];
	else if(i==k) dp[i][j][k]=dp[i-1][j][k-1]+a[i][2];
	else if(j==0&&k==0) dp[i][j][k]=dp[i-1][j][k]+a[i][3];
	else if(j==0) dp[i][j][k]=max(dp[i-1][j][k-1]+a[i][2],dp[i-1][j][k]+a[i][3]);
	else if(k==0) dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],dp[i-1][j][k]+a[i][3]);
	else if(j+k==i) dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][1],dp[i-1][j][k-1]+a[i][2]);
	else dp[i][j][k]=max({dp[i-1][j-1][k]+a[i][1],dp[i-1][j][k-1]+a[i][2],dp[i-1][j][k]+a[i][3]});	
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min((long long)i,n/2);j++)
			{
				for(int k=0;k<=min((long long)i-j,n/2);k++) 
				{
					if(i-j-k>n/2) continue;
					solve(i,j,k);
				}
			}
		}
		long long ans=0;
		for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=min((long long)n-i,n/2);j++) ans=max(ans,dp[n][i][j]);
		}
		cout<<ans<<endl;
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
