#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], sum[N], ans;
bool vis[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == k) {
			ans++;
			vis[i] = true;
		}
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= n - i + 1; j++) {
			int res = a[j], flag = 0;
			for(int t = j + 1; t <= j + i - 1; t++) { 
				if(vis[j]) {
					flag = 1;
					break;
				}
				res ^= a[t];
				if(vis[t]) {
					flag = 1;
					break;
				}
			}
			if(flag == 0 && res == k) {
				ans++;
				for(int t = j; t <= j + i - 1; t++) vis[t] = true;
			}
		}
	}
	cout << ans;
	return 0;
}


