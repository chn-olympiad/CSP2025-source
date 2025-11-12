#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], vis[100010];
int cnt = 0;
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] == m){
			vis[i] = 1;
			cnt++; 
		}
	}
	for (int i = 1;i <= n;i++){
		int sum = a[i];
		if (vis[i] == 1){
			continue;
		}
		for (int j = i + 1;j <= n;j++){
			if (vis[j] == 1){
				break;
			}
			if ((sum ^ a[j]) == m){
			//	cout << endl << i << " " << j << " " << sum << " " << (sum ^ a[j]) << " ";
				i = j + 1;
				cnt++;
				break;
			}
			sum ^= a[j];
		}
	}
	cout << cnt;
	return 0;
} 
