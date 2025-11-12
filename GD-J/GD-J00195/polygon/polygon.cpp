#include<bits/stdc++.h>
using namespace std;
const int N = 5001;
int n,ans,p = 998244353;
int a[N];
int qian[N*N];
int lg[N];
int dp[N][20];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n < 3) {
		cout<<0; return 0; 
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		dp[i][0]=a[i];
		qian[i] = qian[i-1] + a[i];
	}
	lg[1] = 0;
	for(int i=2;i<=n;i++) lg[i] = lg[i>>1] + 1;
	
	for(int k=1;k<=lg[n];k++) { // 2^1 ~ 2^k
		for(int i=1;i + (1 << k) - 1 <= n;i++) {
			dp[i][k] = max(dp[i][k-1], dp[i + (1 << (k-1) )][k-1]);
		}
	}
	for(int l=1;l<=n;l++) {
		for(int r=l;r<=n;r++) {
			int sum = qian[r] - qian[l-1];
			int llg = lg[r - l + 1];
			int mx = max(dp[l][llg], dp[r - (1 << llg) + 1][llg]);
			if(sum > mx*2) {
				ans++;
				ans %= p;
			}
		}
	}
	cout<<ans;
	return 0;
}
