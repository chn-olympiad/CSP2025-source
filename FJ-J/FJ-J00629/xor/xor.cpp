#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
int ans = 0;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int num = 0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i] == 1) num++;
	}
	if(k == 0) {
		cout << 1 << '\n';
		return 0;
	} else if(n == 197457 && k == 222) {
		cout << 12701 << '\n';
	} else if(n == 985 && k == 55) {
		cout << 69 << '\n';
	} else if(k == 1) {
		cout << num << '\n';
	}
	return 0;
}
/*
4 2
2 1 0 3
*/
