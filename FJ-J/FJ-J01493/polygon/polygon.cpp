#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp[5005][6005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dp[0][0]=1;
	sort(a+1,a+1+n);
	for(int j=1; j<=n; j++) {
		for(int i=a[n]+1; i>=0; i--) {
			if(i<=a[j]) {
				dp[j][i]++;
			}
			dp[j][i]=(dp[j-1][max(i-a[j],0)]%998244353+dp[j-1][i]%998244353)%998244353;
		}
	}
	int ans=0;
	for(int i=3; i<=n; i++) {
		if(ans<0){
			ans+=998244353;
		}
		ans=(ans%998244353+dp[i-1][a[i]+1]%998244353)%998244353;
	}                         
	cout<<ans;
	return 0;
}