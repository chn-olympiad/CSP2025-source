#include<bits/stdc++.h>

using namespace std;

int a[500005];
int n, k;
bool flag = true, vis = true;
long long ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] != 1) flag = false;
		if(a[i] != 0) vis = false;
	}
	if(flag == true && k == 0) {
		cout << n / 2 << endl;
		return 0;
	}
	if(flag == true && k == 1) {
		cout << n << endl;
		return 0;
	}
	if(vis == true && k == 0) {
		cout << n << endl;
		return 0;
	}
	if(vis == true && k == 1) {
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		if(a[i] == k) {
			ans++;
			continue;
		}
		if(a[i] ^ a[i+1] == k) {
			ans++;
			i++;
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}
