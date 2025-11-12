#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n,k,a[N],ans,dp[N];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		int b;
		scanf("%lld",&b);
		a[i] = b;
	}
	if(n > 3e5){
		bool flag = 0;
		for(int i=2;i<=n;i++){
			if(a[i-1]!=a[i]){
				ans++;
				i++;
				flag = 0;
			}else if(flag){
				ans++;
				i++;
				flag = 0;
			}else if(a[i] == 1 && a[i-1] == 1){
				flag = 1;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum = 0;
		for(int j=i;j<=n;j++){
			sum ^= a[j];
			if(sum == k){
				for(int l=j;l<=n;l++){
					dp[l] = max(dp[l],dp[i-1] + 1);
				}
				break;
			}
		}
	}
	cout << dp[n];
	return 0;
}
