#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;
int n,k,a[MAXN],sum[MAXN],dp[MAXN][MAXN];
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	//qwq awa ovo
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		dp[i][i]=(a[i]==k);
	}
	for(int len=2;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			dp[i][j]=((sum[j]^sum[i-1])==k);
			for(int mid1=i;mid1<j;mid1++)
				for(int mid2=mid1+1;mid2<=j;mid2++)
					dp[i][j]=max(dp[i][j],dp[i][mid1]+dp[mid2][j]);
		}
	cout<<dp[1][n];
	return 0;
}
