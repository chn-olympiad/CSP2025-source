#include <bits/stdc++.h>
using namespace std;
long long n, k, ans, pan = false, pp;
long long xxor;
vector <long long> a(5e5 + 5);
vector <bool> f(5e5 + 5, true);
void ccf(int left, int right) {
	bool pp = 1;
	for(int j = left; j <= right; j++) {
		for(int x = j + 1; x <= right; x++) {
			if(f[x]) {
				xxor ^= a[x];
				if(xxor == k) {
					ans++;
					f[x] = false;
					k = 0;
				}
			}
			ccf(x + 1, right);
		}
	}
	if(pp)	return ;
}	
void answer() {
	for(int i = 0; i < n; i++) {
		if(f[i] == false) {
			pan = true;
			continue;
		}	else if(pan) {
			xxor = a[i];
			continue;
		}	else {
				long long left = i, right;
				for(int j = i; ; j++) {
					if(f[j] == false) {
					right = j - 1;
					cout << left << " " << right;
					break;
				}
				ccf(left, right);
			}
		}
	}	
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	f[n + 1] = false;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(k == a[i]) {
			ans++;
			f[i] = false;
		}
	}
	answer();
	cout << ans + 1 << endl;
	return 0;
}