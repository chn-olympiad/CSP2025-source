#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long a[500010], n, k, fla = 1, flb = 1, ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) fla = 0;
		if (a[i] > 1) flb = 0;
	}
	if (fla) {
		cout << n / 2;
	} else if (flb) {
		a[0] = -1;
		if (k == 1) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == k) {
					ans++;
					//	cout << i << " " << ans << endl;
					a[i] = -1;
				} else if (a[i] != a[i - 1] && a[i] != -1 && a[i - 1] != -1) {
					ans++;
					//	cout << i << " " << i + 1 << " " << ans << endl;
					a[i] = -1;
					a[i - 1] = -1;
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == k) {
					ans++;
					//	cout << i << " " << ans << endl;
					a[i] = -1;
				} else if (a[i] == a[i - 1] && a[i] != -1 && a[i - 1] != -1) {
					ans++;
					//	cout << i << " " << i + 1 << " " << ans << endl;
					a[i] = -1;
					a[i - 1] = -1;
				}
			}
		}
		cout << ans;
	}
	else{
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) {
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}