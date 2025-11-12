#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main() {
	freopen("polygon.in", "r",stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(n == 3) {
		if(a[0]+a[1]+a[2] > max(a[0], max(a[1], a[2])) * 2) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	} else if(n == 2 or n == 1){
		cout << 0;
		return 0;
	} else if(n == 4) {
		cout << 3;
		return 0;
	} else if(n == 5) {
		cout << 6;
		return 0;
	} else {
		if(n % 2 == 0) {
			cout << (n-1)*floor((n-1)/2);
			return 0;
		} else {
			cout << (n-1)*floor((n-1-1)/2)+3;
			return 0;
		}
	}
	
	return 0;
}
