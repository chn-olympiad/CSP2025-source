#include<bits/stdc++.h>
using namespace std;
int n, x, a[5005];
long long dp[10500], p=998244353, ans=0;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	dp[0]=1;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) {
		x=a[i];
		for(int j=x+1; j<=10001; j++) ans=(ans+dp[j])%p;
		for(int j=10001+x; j>=x; j--) {
			int J=j, k=j-x;
			if(j>10001) J=10001;
			dp[J]=(dp[J]+dp[k])%p;
		}
	}
	//for(int i=1; i<=20; i++) cout<<dp[i]<<"\n";
	cout<<ans;
	return 0;
}
