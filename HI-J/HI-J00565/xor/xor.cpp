#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N], b[N][N], c[N][2], d[N];

int main (void){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	if (n <= 2){
		cout << 0;
		return 0;
	}
	
	int flag = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] != 1){
			flag = 1;
		}
		cin >> a[i];
	}
	if (flag == 0){
		if (n % 2 == 1){
			cout << (n - 1)/2;
			return 0;
		} else {
			cout << n/2;
		}
	} 
	
	return 0;
}
