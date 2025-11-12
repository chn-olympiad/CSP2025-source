#include <bits/stdc++.h>
using namespace std;
int a[510];
int mod = 998244353;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, ret = 1;
	cin >> n >> m;
	bool flag = 0, h1 = 0;
	string x;
	cin >> x;
	for (int i = 0; i < n; i++){
		if (x[i] == 0) flag = 1;
		else h1 = 1;
	}
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ret = ret * ((i + 1) % mod) % mod;
	}
	if (h1 == 1 && m == 1) cout << ret;
	else if (n == m && flag == 0) cout << 1;
	else cout << 0;
	cout << 0;
}
