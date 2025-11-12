#include <bits/stdc++.h> 
using namespace std;
long long a[500007];
long long ans[500007];
bool visit[500007];
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k; 
	long long res = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		visit[i] = false;
		ans[i] = INT_MIN;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (visit[j] == true) break;
			if (j == 0) ans[i] = a[j];
			else ans[i] ^= a[j];
		//	cout << ans[i] << " ";
			if (ans[i] == k) {
				res += 1;
				for (int k = i; k <= j; k++) {
					visit[k] = true;
				}
		//		cout << endl;
			}
		}
	}
	cout << res;
	return 0;
}
