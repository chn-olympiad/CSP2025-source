#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105], p, q;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	p = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = n * m; i >= 1; i--){
		if (a[i] == p){
			q = n * m - i + 1;
			break;
		}
	}
	for (int i = 1; i <= m; i++){
		if (i % 2 == 0){
			for (int j = n; j >= 1; j--){
				if (q == 1){
					cout << i << " " << j;
				}
				q--;
			}
		}
		else{
			for (int j = 1; j <= n; j++){
				if (q == 1){
					cout << i << " " << j;
				}
				q--;
			}
		}
	}
	return 0;
} 
