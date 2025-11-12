#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int arr[500005], ans = 0, cur = 0, n, k, f[500005],sum[500005], fmaxx, allmax=0;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> k;
	sum[0] = 0;
	for(int i = 1;i <= n;i++) cin >> arr[i] , sum[i] = sum[i-1] ^ arr[i],allmax=max(allmax,arr[i]);
	if (k == 0 && allmax == 1) {
		cout << n / 2;
		return 0;
	}
	if (k == 1 && allmax == 1){
		ans = 0;
		cur = arr[1];
		for(int i = 2;i <= n;i++) {
			if (cur == k) cur = arr[i], ans++;
			else cur ^= arr[i];
		}
		if (cur == k) ans++;
		cout << ans;
	} else {
		// Çø¼ä: [i, j] -> sum[j] ^ sum[i - 1] 
		for (int i = 1;i <= n;i++){
			fmaxx = 0;
			for (int j = 1;j <= i;j++){
				if (i == j){
					fmaxx = max(fmaxx, int(arr[i] == k));
					f[i] = max(f[i], fmaxx);
					continue;
				}
				fmaxx = max(fmaxx, f[j]);
				if((sum[i] ^ sum[j]) == k) {
					f[i] = max(f[i], fmaxx + 1);
				}
			}
		}
		for (int i = 1;i <= n;i++) ans = max(ans, f[i]);
		cout << ans;
	}
	return 0;
}
