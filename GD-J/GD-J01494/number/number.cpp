#include <bits/stdc++.h>
using namespace std;
int n[11];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++){
		if (a[i] >= '0' && a[i] <= '9'){
			int m;
			m = int(a[i] - '0');
			n[m]++;
		}
	}
	for (int i = 9; i >= 0; i--){
		for (int j = 1; j <= n[i]; j++){
			cout << i;
		}
	}
	return 0;
} 
