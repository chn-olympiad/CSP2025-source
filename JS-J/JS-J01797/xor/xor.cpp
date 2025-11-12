#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e5;
int n, k, dp[N + 5];
int ans;
int a[N + 5];
int flag = 0;
int flag2 = 0;
signed main(){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		if (a[i] != 1) flag = 1;
		if (a[i] >= 2) flag2 = 1;
	}
	
	if (flag == 0){
		cout << n / 2 << endl;
		return 0;
	}
	
	if (flag2 == 0){
		if (k == 0){
			int cnt1 = 0;
			int cnt2 = 0;
			for (int i = 1; i <= n; ++ i){
				if (a[i] == 0){
					cnt2 ++;
					ans = ans + cnt1 / 2;
					cnt1 = 0;
				}
				if (a[i] == 1) cnt1 ++;
			}
			cout << ans + cnt2 << endl;
		}
		else if (k == 1){
			for (int i = 1; i <= n; ++ i){
				if (a[i] == 1) ans ++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}

/*
 4 2
 2 1 0 3
 
 
 
 4 3
2 1 0 3



4 0
2 1 0 3
*/
 
 
