#include<bits/stdc++.h>
using namespace std;
const int N=500001;
int a[N];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int dp[n][k];
	int s,q;
	for(int i=1;i<=n;i++)
	{
		for(int j=k;j>=0;j--)
		{
			if(a[i]==j) dp[i][j]=dp[i-1][j]+1;
			else
			{
				s=a[i];
				q=i;
				while(s!=j&&q>=1)
					s=s xor a[--q];
				if(s==j) dp[i][j]=dp[q-1][j]+1;
				else dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][k];
	return 0;
}
