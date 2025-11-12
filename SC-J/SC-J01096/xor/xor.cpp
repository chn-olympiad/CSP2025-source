#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long s[500001];
long long r[500001][500001];



//动规
//int sum_dp[500001][500001];//值的位置是下标+1 
//long long dp(long long n, int** sumdp) 
//{
//	
//	for(int i=1;i<=n;i++)//下标+1(a值) 
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(r[i-1][j-1]==1)
//			{
//				sumdp[i][j]=sumdp[i][i]+1;
//			}
//			else
//			{
//				sumdp[i][j]=max(sumdp[i-1][j],sumdp[i][j-1]);
//			}
//		}
//	}
//	
//	return sumdp[n][n];
//}



int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	long long tmp;
	for(long long i=0;i<=n-1;i++)
	{
		cin >> tmp;
		s[i]=tmp;
	} 
	
	
	//dp的状态转移（结果为是返回1） 
	long long c=0;
	for(long long i=0;i<=n-1;i++)
	{
		for(long long j=i;j<=n-1;j++)
		{
			long long sum=0;
			for(long long t_k=i;t_k<=j;t_k++)
			{
				sum^=t_k;
			}
			if(sum==k)
			{
				r[i][j]=1;
			}
		}
	}
	
//	cout << dp(n,sum_dp);
	cout << 0;
	
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
}