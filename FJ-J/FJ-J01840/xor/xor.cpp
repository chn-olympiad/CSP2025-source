#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, a[500005];
bool xzA = 1, xzB = 1;

void solve1() {
	if(k > 1) {
		cout << "0\n";
		return;
	}
	if(k == 0) {
		cout << n / 2 << "\n";
		return;
	}
	cout << n << "\n";
	return;
}

void solve2() {
	if(k > 1) {
		cout << "0\n";
		return;
	}
	int cnt0 = 0, cnt1;
	for(int i = 1;i <= n;i ++) {
		cnt0 += (a[i] == 0);
	}
	cnt1 = n - cnt0;
	if(k == 1) {
		cout << cnt1 << "\n";
		return;
	}
	int tmp = 0, ans = cnt0;
	for(int i = 1;i <= n;i ++) {
		if(a[i] == 1) {
			tmp ++;
		}else {
			ans += tmp / 2;
			tmp = 0;	
		}
	}
	if(tmp) {
		ans += tmp / 2; tmp = 0;
	}
	cout << ans << "\n";
	return;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		if(a[i] != 1 && a[i] != 0) xzB = 0;
		if(a[i] != 1) xzA = 0; 
	}
	if(xzA) solve1();
	else if(xzB) solve2();
	else cout << n / 2;
	return 0;
}
