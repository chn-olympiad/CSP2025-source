#include<bits/stdc++.h>
//xor
using namespace std;
const int N = 5e5 + 25;
long long n, k, a[N], sum[N], ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	a[0] = 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != k) {
			if (sum[i - 1] == -1) {
				sum[i] = a[i] ^ 0;
			}
			else {
				sum[i] = a[i] ^ sum[i - 1];
			}
			
		}
		else {
			sum[i] = -1;
		}
	}
	for (int r = 1; r <= n; r ++) {
		if (sum[r] == -1) {
			ans ++;
			continue;
		}
		else {
			for (int l = r - 1; l >= 1; l --) {
				if (sum[l] == -1) {
					break;
				}
				else {
					long long fff = sum[r] ^ sum[l];
					if (fff ^ k == 0) {
						sum[r] = -1;
						ans ++;
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
