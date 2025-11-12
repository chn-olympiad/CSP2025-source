#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[100010], sum[10001], cnt = 0, l = 0;
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i + 2];
	}
	sort(a + 2, a + 2 + n);
	for (int i = 1;i <= n;i++){
		sum[i + 2] = sum[i + 1] + a[i + 2];
	}
	for (int i = 1;i <= n;i++){
		if (sum[i + 1] > a[i + 2]){
			for (int j = 1;j < i;j++){
				for (int k = j + 1;k < i;k++){
					if (sum[k + 2] - sum[j + 1] > a[i + 2]){
						//cout << j << " " << i << " " << sum[i + 1] <<endl;
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt % 998244353;
	return 0;
} 
