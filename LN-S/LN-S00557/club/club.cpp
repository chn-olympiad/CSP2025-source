#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	int ans[t];
	for(int i = 0;i<t;i++) {
		ans[i] = 0;
		cin >> n;
		int a[n], b[n], c[n];
		for(int j = 0;j<n;j++) {
			cin >> a[j] >> b[j] >> c[j];
		}
		ans[i] = a[0]*n;
	}
		
	for(int j = 0;j<t;j++) {
		cout << ans[j] << endl;
	}
	return 0;
}
