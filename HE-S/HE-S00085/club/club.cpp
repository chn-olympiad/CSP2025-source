#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		int maxn = 0;
		int a[100005][5];
		int dp[100005];
		int b[3] = {};
		for (int j = 1; j <= n; j++){
			cin >> a[j][1] >> a[j][2] >> a[j][3];
		}
		for (int j = 1; j <= n; j++) {
			if (b[0] <= n / 2 && b[1] <= n / 2 && b[2] <= n / 2) {
				if(a[j][1] >= a[j][2]){
					if (a[j][1] >= a[j][3]){
						maxn += a[j][1];
						b[0] += 1;
					} else {
						b[2] += 1;
						maxn += a[j][3];
					}
				} else if(a[j][2] >= a[j][3]){
					maxn += a[j][2];
					b[1] += 1;
				} else {
					b[2] += 1;
					maxn += a[j][3];
				}
				
			} else {
				if (b[0] >= n / 2){
					maxn += max(a[j][2], a[j][3]);
				} else if (b[1] >= n / 2) {
					maxn += max(a[j][1], a[j][3]);
				} else {
					maxn += max(a[j][1], a[j][2]);
				}
			}
		}
		cout << maxn << endl;
	}
	return 0;
}
