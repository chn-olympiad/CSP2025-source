#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
int a[N];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a+1, a+1+n);
	if (a[n] == 1){
		cout << n;
	} else {
		int mx = a[3];
		int sum = 0;
		if (n == 3){
			sum = sum + a[1] + a[2] + a[3];
			if (mx * 2 < sum){
				cout << 1;
				return 0;
			} else {
				cout << 0;
				return 0;
			}
		} 
	}
	return 0;
} 
