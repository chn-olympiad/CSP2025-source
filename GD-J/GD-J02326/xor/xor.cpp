#include<bits/stdc++.h>
using namespace std;
int n, k;   
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int ans = 0;
	int a[n + 1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int l = i, r = i + 1, t = a[i], mans = 0;
		while(r <= n + 1) {
			//cout << r << endl;
			if(t == k) {
				l = r;
				t = a[r];
				r++;
				mans++;
				continue;
			}
			t ^= a[r];
			r++;
		}
		ans = mans > ans ? mans : ans;
	}
	cout << ans;
	return 0;
}
