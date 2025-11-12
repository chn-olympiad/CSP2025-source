#include <bits/stdc++.h>
#define N 15
using namespace std;
int n, m;
int a[105];
int main(){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int tot = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[++tot];
		}
	}
	int num = a[1];
	int k = 0;
	sort(a + 1, a + n * m + 1);
//	for (int i = 1; i <= n * m; i++){
//		cout << a[i] << " ";
//	}
	for (int i = 1; i <= n * m; i++){
		if (a[i] == num) {
			k = i;
//			cout << k << "\n\n";
			break;
		}
	}
	k = n * m + 1 - k;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (i&1) {
			for (int j = 1; j <= n; j++){
				cnt++;
				if (cnt == k) {
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
		else {
			for (int j = n; j >= 1; j--){
				cnt++;
				if (cnt == k) {
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
	}
	
	return 0;
} 
