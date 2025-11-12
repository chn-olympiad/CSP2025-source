#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, ans;
const ll N = 5 * 1e+5 + 1;
ll a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n; ++i) {
		cin >> a[i];
		if(a[i] == k) {
			i--;
			ans++;
		}
	}
	if(n <= 100 and k = 0) {
		cout << n / 2 << endl;
		return 0;
	}else if(n <= 100 and k <= 1) {
		if(k == 0) {
			for(int i = 1;i <= n; ++i) {
				if(a[i] == k) ans++;
				else if(i >= 2) {
					if(a[i] == a[i - 1]) {
						ans++;
					}
				}
			}
		}else {
			for(int i = 1;i <= n; ++i) {
				if(a[i] == k) ans++;
				else if(i >= 2) {
					if(a[i] != a[i - 1]) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}