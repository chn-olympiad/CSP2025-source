#include <bits/stdc++.h>
using namespace std;
#define int long long
#define len 101000
#define len2 220
#define inf 0x3f3f3f3f
int t, n, a[len], b[len], c[len], d[len], ans;
int dp[len2][len2][2];
void solve1() {
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++) dp[i][j][0]=-inf;
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++) {
		int x=i&1, y=(i+1)&1;
		for(int j=0;j<=n/2;j++) for(int k=0;k<=n/2;k++) dp[j][k][x]=-inf;
		for(int j=0;j<=n/2&&j<=i;j++) {
			for(int k=0;j+k<=i&&k<=n/2;k++) {
				if(i-j-k>n/2) continue;
				if(j) dp[j][k][x]=max(dp[j][k][x], dp[j-1][k][y]+a[i]);
				if(k) dp[j][k][x]=max(dp[j][k][x], dp[j][k-1][y]+b[i]);
				if(i-j-k) dp[j][k][x]=max(dp[j][k][x], dp[j][k][y]+c[i]);
			}
		}
	}
	ans=0;
	for(int i=0;i<=n/2;i++) 
		for(int j=0;j<=n/2;j++) 
			if(n-i-j<=n/2) 
				ans=max(ans, dp[i][j][0]);
	cout<<ans<<endl;
	return;
}
void solve2() {
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i], ans+=a[i], d[i]=b[i]-a[i];
	sort(d+1,d+n+1);
	for(int i=n/2+1;i<=n;i++) ans+=d[i];
	cout<<ans<<endl;
	return;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n<=200) solve1();
		else solve2();
	}
	return 0;
}
