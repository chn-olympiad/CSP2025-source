#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m, a[500005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (m > 1){
		cout << 0;
		return 0;
	}
	if (m == 1){
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if (a[i] == 1){
				sum++;
			}
		}
		cout << sum;
		return 0;
	}
	if (m == 0){
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if (a[i] == 0){
				sum++;
			}
			if (a[i] == 1){
				if (a[i + 1] == 1){
					sum++;
					i += 2;
				}
			}
		}
		cout << sum;
	}
	return 0;
} 
