#include<bits/stdc++.h>
using namespace std;
long long a[500005],su; 
int ans, now=1;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		su = a[i];
		if(su == k) {
			ans++;
			now = i;
			continue;
		}
		for(int j = i-1; j > now; j --) {
			su ^= a[j];
			if(su == k) {
				ans++;
				now = i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
