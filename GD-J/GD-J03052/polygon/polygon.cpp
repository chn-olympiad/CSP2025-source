#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n,a[5005],c[5005][5005],ans,dp[5005];
void Init() {
	for (int i = 1; i <= 5000; i ++) {
		for (int j = 1; j <= i; j ++) {
			if (i == j || j == 1) c[i][j] = i;
			else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
		}
	}
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	Init();
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a+1,a+n+1);
	if (a[1] == 1 && a[n] == 1) {
		for (int i = 3; i <= n; i ++) ans = (ans+c[n][i])%mod;
		cout << ans;
		exit(0);
	}
	for (int i = 1; i <= 2; i ++) {
		int mx = 0,sum = 0;
		if (i == 1) mx = max(a[1],mx),sum += a[1];
		for (int i = 1; i <= 2; i ++) {
			if (i == 1) mx = max(a[2],mx),sum += a[2];
			for (int i = 1; i <= 2; i ++) {
				if (i == 1) mx = max(a[3],mx),sum += a[3];
				for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[4],mx),sum += a[4];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[5],mx),sum += a[5];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[6],mx),sum += a[6];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[7],mx),sum += a[7];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[8],mx),sum += a[8];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[9],mx),sum += a[9];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[10],mx),sum += a[10];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[11],mx),sum += a[11];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[12],mx),sum += a[12];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[13],mx),sum += a[13];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[14],mx),sum += a[14];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[15],mx),sum += a[15];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[16],mx),sum += a[16];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[17],mx),sum += a[17];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[18],mx),sum += a[18];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[19],mx),sum += a[19];
					for (int i = 1; i <= 2; i ++) {
					if (i == 1) mx = max(a[20],mx),sum += a[20];
					
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				}
				
			}
		}
		if (sum > 2*mx) ans ++;
	}
	cout << ans;
	return 0; 
}

