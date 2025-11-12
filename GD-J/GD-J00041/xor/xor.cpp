#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005];
int sum[500005];
int dp[500005];
unordered_map<int,int> st;
unordered_map<int,int> vis;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	vis[0]=1;
	for(int i=1;i<=n;i++) {
		dp[i]=dp[i-1];
		int temp=sum[i]^k;
		if(vis[temp]) dp[i]=max(dp[i],st[temp]+1);
		st[sum[i]]=max(st[sum[i]],dp[i]);
		vis[sum[i]]=1;
//		for(int j=0;j<i;j++) {
//			if((sum[i]^k)==sum[j]) dp[i]=max(dp[i],dp[j]+1);
//		}
	}
	cout<<*max_element(dp+1,dp+n+1);
	return 0;
}
