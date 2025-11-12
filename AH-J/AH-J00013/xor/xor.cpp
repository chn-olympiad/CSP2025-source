#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+5;
int n,k;
int a[N];
int sum[N];
int dp[N];
int ans=INT_MIN;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
