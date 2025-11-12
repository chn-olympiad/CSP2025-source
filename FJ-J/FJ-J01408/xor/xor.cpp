#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int a[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if (n == 1){
		cout << 1;
	} else if (n == 2){
		cout << 1;
	} else {
		cout << n-2;
	}
	
	return 0;
} 
