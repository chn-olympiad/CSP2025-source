#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int arr[n*m+7], r;
	for (int i = 0; i < n*m; i++) {
		cin >> arr[i];
		if (i == 0) {
			r = arr[i];
		}
	}
	
	sort(arr, arr + n*m, greater<int>());
	
	int z = 0;
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				if (arr[z] == r) {
					cout << i+1 << ' ' << j+1;
					return 0;
				}
				z++;
			}
		} else {
			for (int j = n-1; j >= 0; j--) {
				if (arr[z] == r) {
					cout << i+1 << ' ' << j+1;
					return 0;
				}
				z++;
			}
		}
	}
	
	return 0; 
}
