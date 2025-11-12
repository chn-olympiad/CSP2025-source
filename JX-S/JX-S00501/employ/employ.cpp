#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 7;
int n, m, b, cnt = 0, cnt1 = 0;
string s;
int a[N];

int pow(int b){
	int a = 1;
	
	while(b != 1) {
		a *= b;
		a %= 998244353;
		b--;
	}
	a = a / 2;
	return a;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	b = n;
	cnt = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0) {
			cnt++;
		}
		if(s[i] == '0') {
			cnt1++;
		}
	}
	if(m == 1) {
		if(cnt1 >= n - cnt - 1) {
			cout << pow(n - cnt);
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	if(m == n && cnt1 == 0) {
		cout << pow(n);
		cout << cnt1;
		return 0;
	}
	cout << pow(n) - 1;
	return 0;
}
