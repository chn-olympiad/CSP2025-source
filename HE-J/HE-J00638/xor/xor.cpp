#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,INF=1e18;
int n,k;
int a[N],sum[N],dp[N],pre[(1<<20)+5];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1; i<(1<<20); i++)pre[i]=-INF;
	for(int i=1; i<=n; i++) {
		dp[i]=dp[i-1];
		int x=sum[i]^k;
		if(pre[x]!=-INF) {
			dp[i]=max(dp[i],dp[pre[x]]+1);
		}
		pre[sum[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
/*
4 2
2 1 0 3

2

4 3
2 1 0 3

2

4 0
2 1 0 3

1
*/
