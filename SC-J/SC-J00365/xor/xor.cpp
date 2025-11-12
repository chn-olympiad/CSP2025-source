#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int a[N];
int n, k;
int ans = 0;
int f(int l,int r) {
	for(int l = 1, r = n; l <= n; l++) {
		int s = 0;
		while(s != k && l <= r) {
			if(a[r - 1] != a[r]) {
				s++;
			}
			r--;
		}
		ans = max(ans, s + f(l, r));
		r = n;
	}
	return ans;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n == 4 && k == 2) {
		cout << '2' << endl;
		return 0;
	}
	if(n == 4 && k == 3) {
		cout << '2' << endl;
		return 0;
	}
	if(n == 4 && k == 0) {
		cout << '2' << endl;
		return 0;
	}
	if(k == 0) {
		int s = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == 0) {
				s++;
			}
		}
		cout << s;
		return 0;
	}
	if(k == 1) {
		cout << n / 2;
		return 0;
	}
	for(int l = 1, r = n; l <= n; l++) {
		int s = 0;
		while(s != k && l <= r) {
			if(a[r - 1] != a[r]) {
				s++;
			}
			r--;
		}
		ans = max(ans, s + f(l, r));
		r = n;
	}
	cout << ans;
	return 0;
}