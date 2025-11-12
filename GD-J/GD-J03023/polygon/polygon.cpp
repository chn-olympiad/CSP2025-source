#include<bits/stdc++.h>
using namespace std;

int n;
int arr[5010];

int main() {
//	freopen("polygon.in", "r", stdin);
//	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if(n < 3) {
		cout << 0 << endl;
	}
	else if(n == 3){
		sort(arr + 1, arr + 1 + n);
		if(arr[1] + arr[2] > arr[3]) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		int ans = 0;
		for(int i = 3; i <= n; i++) {
			int temp = 1;
			for(int j = 0; j < i; j++) {
				temp *= (n - j);
			} 
			for(int j = 1; j <= i; j++) {
				temp /= j;
			}
			ans += temp;
		}
		cout << ans << endl;
	}
	return 0;
}
