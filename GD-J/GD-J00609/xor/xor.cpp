#include <bits/stdc++.h>
using namespace std; 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, ans=0;
    cin >> n >> k;
    int sum[n+5][n+5] = {};
    for (int i = 0; i < n; i++) {
    	cin >> sum[i][i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum[i][j] = sum[i][j-1] ^ sum[j][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum[i][j] = sum[i][j-1] ^ sum[j][j];
			if (sum[i][j] == k) {
				ans++;
				i = j+1;
				j*=2;
			}
		}
	}
	cout << ans;
	return 0;
}
