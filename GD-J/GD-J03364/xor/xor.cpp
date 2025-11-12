#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 500010
int n, x;
int a[N];

int xr[N];//前缀异或  
int dp[N];
//dp[i]表示选到第i位时最多有几段  

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> x;
	bool Bt = true;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		xr[i] = xr[i - 1] ^ a[i];
		if(a[i] > 1) {
			Bt = false;
		}
	}
	
	if(n >= 200000 && Bt == true) {
		if(x == 0) {
			//x=0,选两个1连续和单独0 
			int cnt21 = 0, cnt0 = 0;
			for(int i = 1;i <= n;i++) {
				if(a[i] == 0) {
					cnt0++;
				}
				if(a[i] == 1 && a[i + 1] == 1) {
					cnt21++;
					i++;
				}
			} 
			cout << cnt21 + cnt0 << "\n";
		} else {
			//x=1,选单独1(1、0混一起区间更少) 
			int cnt1 = 0;
			for(int i = 1;i <= n;i++) {
				if(a[i] == 1) {
					cnt1++;
				}
			}
			cout << cnt1 << "\n";
		}
	} else {
		//使用dp  
		for(int i = 1;i <= n;i++) {
			dp[i] = dp[i - 1];
			for(int j = 1;j <= i;j++) {
				//找到上一个位置  
				int xrnum = xr[i] ^ xr[j - 1];
				if(xrnum == x) {
					dp[i] = max(dp[i], dp[j - 1] + 1);
				}
			}
		}
		cout << dp[n] << "\n";
	}
	return 0;
}
