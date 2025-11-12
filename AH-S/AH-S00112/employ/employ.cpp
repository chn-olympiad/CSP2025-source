#include <bits/stdc++.h>
using namespace std;
int n, m; string s;
int ifgo[501]; int rn[501];
long long ans;
bool ifallis1 = 1; int rnis0 = 0, cangosum = 0;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		if(s[i-1] == '1') ifgo[i] = 1, cangosum++;
		else ifgo[i] = 0, ifallis1 = 0;
	}
	for(int i = 1; i <= n; i++) {
		cin >> rn[i];
		if(rn[i] == 0) rnis0++;
	}
	
	if((m + rnis0) > n || cangosum < m) {cout << "0"; return 0;}
	
	if(ifallis1) {
		ans = n;
		for(int i = 2; i <= n; i++) {
			ans *= 1LL * n; ans = ans % 998244353;
		}
		cout << ans; return 0;
	}
	
	cout << "0";
	
	return 0;
}
