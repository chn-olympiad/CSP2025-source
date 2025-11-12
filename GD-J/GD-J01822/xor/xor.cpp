#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,dp[5005][5005];
bool f[500005];
int xo(int l,int r){
	long long s = a[l];
	for (int i = l + 1;i <= r;i++) s ^= a[i];
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int len = 1;len <= n;len++){
		for (int l = 1;l <= n;l++){
			bool fl = true;
			for (int i = l;i <= l + len - 1;i++){
				if (f[i]) fl = false;
			}
			if (!fl) continue;
			if (xo(l,l + len - 1) == k){
				for (int i = l;i <= l + len - 1;i++) f[i] = true;
				ans++;
				cout << l << " " << l + len - 1 << endl; 
			}
		}
	}
	/*for (int l = 1;l <= n;l++){
		for (int i = l;i <= n;i++){
			long long ma = 0,ma2 = 0;
			for (int j = 1;j <= l;j++){
				ma = max(ma,dp[i - 1][j]);
				ma2 = max(ma2,dp[i - l][j]);
			}
			if (xo(i - l + 1,i) == k) dp[i][l] = max(ma,ma2 + 1);
			else dp[i][l] = ma;
		}
	}
	for (int l = 1;l <= n;l++){
		for (int i = l;i <= n;i++) cout << dp[i][l] << " ";
		cout << endl;
	}
	for (int l = 1;l <= n;l++){
		ans = max(ans,dp[n][l]);
	}*/
	cout << ans;
	return 0;
}
