#include<bits/stdc++.h>
using namespace std;
int a[5003];
int dp[5003];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1;i<=n;i++) {
		dp[i]=a[i]+a[i-1];
	}
	long long ans=0;
	for (int i=n;i>=1;i--) {
		for (int l=1;l<n;l++) {
			for (int r=2;r<=n;r++) {
				if (n*2<dp[r]-dp[l-1]) {
					ans++;
					ans%=998244353;
				}
			}
		}
	} 
//	for (int i=0;i<=n;i++) {	
//		int cnt=0;
//		for (int j=1;j<=n;j++) {
//			if (j!=i) cnt+=a[i];
//		}
//		if (cnt>2*a[n]&&i!=n) {
//			cout << cnt;
//			cout << endl << i;
//			return 0;
//		} else if (cnt>2*a[n-1]) {
//			cout << cnt;
//			cout << endl << i;
//			return 0;
//		}
//	}
	cout << ans;
	return 0;
}
