#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 5e5 + 5;
int a[N];
int ans;
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int sum = a[i];
		int sum2 = 0;
		for (int j = i; j < n; j++) {
			if (i == j) {
				sum2 = a[i];
				if (sum == k) {
					ans++;
				}
				continue;
			}
			for (int w = i; w <= j; w++) {
				sum ^= a[w];
				sum2 += a[w];
			}
			if (sum2 == k) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
	//老师，为啥我dp过不了啊啊啊啊啊啊（估计没人看到，有人看到的话，能给我家一百分吗 )   ：） 
}
