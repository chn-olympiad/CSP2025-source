#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N=5e5+10;
int a[N];
int pre[N];
int sumx[N];
int dp[N];
int m[4*N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sumx[i]=sumx[i-1]^a[i];
		m[sumx[i]]=i;
		pre[i]=m[sumx[i]^k];
	}
	dp[0]=-1e18;
	for(int i=1;i<=n;i++){
		if(sumx[i]==k) dp[i]=max(1*1ll,max(dp[pre[i]]+1,dp[i-1]));
		else
		dp[i]=max(0*1ll,max(dp[pre[i]]+1,dp[i-1]));
	}
	cout<<dp[n];
	return 0;
}
