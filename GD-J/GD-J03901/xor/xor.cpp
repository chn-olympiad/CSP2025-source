#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int n,a[N],k,dp[N],sum[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		sum[i] = (sum[i-1] ^ a[i]);
//		cout<<sum[i]<<" ";
	}
//	cout<<endl;
	if(a[1] == k) dp[1]=1;
//	cout<<dp[1]<<" ";
	for(int i = 2; i<=n; i++){
		int j = i-1;
		dp[i] = dp[i-1];
		if(a[i] == k) dp[i]=max(dp[i],1ll*1);
		while(j>=0 && (sum[i] ^ sum[j]) != k) j--;
		if((sum[i] ^ sum[j]) == k && j>=0){
			dp[i] = max(dp[i],dp[j]+1);
		}
//		cout<<j<<" "<<dp[i]<<endl;
	}
//	cout<<endl;
	cout<<dp[n]<<endl;
	return 0;
}
