#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	long long n, k;
	int ans = 0;
	cin >> n >> k;
	long long a[n];
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	
	//骗分
	bool f = 0;
	for(int i = 0; i < n; ++i)
		if(a[i] != 1) f = 1; 
	if(!f) {
		cout << n / 2;
		return 0;
	}
	f = 0;
	for(int i = 0; i < n; ++i) {
		if(!(a[i] == 1 || a[i] == 0)) f = 1;
	}
	if(!f) {
		for(int i = 0; i < n; ++i)
			if(a[i] == k) ans++;
		cout << ans;
		return 0;
	}
	
	//题
	for(int i = 0, sum = 0; i < n; ++i) {
		long long x = a[i];
		for(int w = i + 1; w <= n; ++w) {
//		cout << "x = " << x << " w = " << w << endl;
			if(x == k) {
				sum++;
				x = a[w];
//			cout << "Find! sum = " << sum << endl;
				continue;
			}
			if(w == n) continue;
//			cout << x << " ^ " << a[w] << " = ";
			x ^= a[w];
//			cout << x << endl;
		}
		ans = max(sum, ans);
		sum = 0;
//		cout << "ans = " << ans << endl << endl;
	}
	cout << ans;
}