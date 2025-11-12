#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int c[1048576+10],q[N],dp[N],a[N],s=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=1048576;i++)c[i]=-1;
	c[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]^a[i];
		dp[i]=dp[i-1];
		if(c[q[i]^k]>=s&&c[q[i]^k]!=-1)
		{
			s=i;
			dp[i]++;
		}
		c[q[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
