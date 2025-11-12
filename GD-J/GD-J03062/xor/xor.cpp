#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int a[N];
int ans = -1;
int n,k;
int dp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1; i <= n; i++){
		dp[i] = max(dp[i],dp[i - 1]);
		int sum = 0;
		for(int j = i; j <= n; j++){
			sum ^= a[j];
			if(sum == k){
				dp[j] = max(dp[j],dp[i - 1] + 1);
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++){
	//	cout << dp[i] << ' ';
		ans = max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
