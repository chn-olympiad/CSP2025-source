#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
int n, k, a[maxn];
bool flag_b = true;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] > 1) flag_b = false; 
	}
	if(flag_b) {
		if(k == 0) {
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				if(a[i] == 0) ans++;
				if(a[i] == 1 && a[i + 1] == 1) {
					ans++;
					i++;
				}
			}
			cout << ans;
			return 0;
		} else {
			int ans = 0;
			for(int i = 1; i <= n; i++) 
				if(a[i] == 1) ans++;
			cout << ans;
			return 0;
		}
	}	
	int ans = 0; 
	for(int i = 1; i <= n; i++) {
		if(a[i] == k) {
			ans++;
			continue;
		}
		int cnt = a[i];
		for(int j = i + 1; j <= n; j++) {
			cnt ^= a[j];
			if(cnt == k) {
				ans++;
				i = j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}