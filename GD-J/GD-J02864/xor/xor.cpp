#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],s[N],l[N],pre[N];
int dp[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]^s[i-1];
		l[s[i-1]]=i;
		pre[i]=l[s[i]^k];
	}
	dp[0]=-1e9;
	for(int i=1;i<=n+1;i++)
	{
		dp[i]=max(dp[i-1],dp[pre[i-1]]+1);
		if(dp[1]<0)dp[1]=0;
	}
	cout<<dp[n+1]<<endl; 
	return 0;
}
