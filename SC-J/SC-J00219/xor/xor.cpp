#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int lst[N];
int dp[N],n,k,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		sum^=x;
		int t=lst[sum^k];
//		cout<<t<<' '<<(sum^k)<<'\n';
		if(t==0){
			dp[i]=(sum==k?1:0);
		}
		else dp[i]=dp[t]+1;
		dp[i]=max(dp[i-1],dp[i]);
		lst[sum]=i;
//		cout<<dp[i]<<' ';
	}
	cout<<dp[n];
	return 0;
}
/*
4 0
2 1 0 3
*/