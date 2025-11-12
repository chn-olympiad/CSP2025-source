#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=1,dp[2][5005],ala,mans=1,mod=998244353;
long long mns (long long aa,long long ab) {
	if (aa<ab) return aa+mod-ab;
	return aa-ab;
}
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		ans=ans<<1ll;
		ans%=mod;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		ala+=a[i-1];
		for (int j=0;j<a[i-1];j++) {
			dp[i%2][j]=dp[(i-1)%2][j];
			mans=(mans+dp[i%2][j])%mod;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
		for (int j=a[i-1];j<=min(ala,a[n]);j++) {
			dp[i%2][j]=dp[(i-1)%2][j-a[i-1]]+dp[(i-1)%2][j];
			if (a[i-1]==0) dp[i%2][j]++;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
			dp[i%2][j]%=mod;
			if (j<=a[i]) mans=(mans+dp[i%2][j])%mod;
		}
	}
	cout<<mns(ans,mans);
	return 0;
}

