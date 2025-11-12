#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int main() {
	IOS;
	freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	long long n, m, ans = 1;
	cin >> n >> m;
	string s;
	cin >> s;
	int l = n;
	int a[510];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0)
			l --;
	}
	for(int i = 1; i <= l; i++) {
		ans *= i;
		ans %= 998244353;
	}
	cout << ans << "\n";
	return 0;
}
	
