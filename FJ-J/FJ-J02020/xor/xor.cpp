#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,N2=1e3+10;
int n,k,a[N],sum[N];
int dp[N2][N2];
int ans;

int qujian(int right,int left)
{
	return sum[left]^sum[right-1];
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	if(n<=2e2+48)
	{
		for(int i=1;i<=n;i++)
		{
			if(qujian(i,i)==k)
				dp[i][i]=1;
		}
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i<=n-len+1;i++)
			{
				int j=i+len-1;
				if(qujian(i,j)==k)
					dp[i][j]+=1;
				for(int k=i;k<j;k++)
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
		ans=dp[1][n];
	}
	else
	{
		int last=1;
		for(int i=1;i<=n;i++)
		{
			if(qujian(last,i)==k)
			{
				ans++;
				last=i+1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
