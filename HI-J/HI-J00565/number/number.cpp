#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int b[N] = {0};


int main (void){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	 
	string a;
	cin >> a;
	int cnt = 0, ans = a.size();
	
	for (int i = 0; i < ans; i++){
		if (a[i] == '1'){
			b[i] = 1;
			cnt++;
		} else if (a[i] == '2'){
			b[i] = 2;
			cnt++;
		} else if (a[i] == '3'){
			b[i] = 3;
			cnt++;
		} else if (a[i] == '4'){
			b[i] = 4;
			cnt++;
		} else if (a[i] == '5'){
			b[i] = 5;
			cnt++;
		} else if (a[i] == '6'){
			b[i] = 6;
			cnt++;
		} else if (a[i] == '7'){
			b[i] = 7;
			cnt++;
		} else if (a[i] == '8'){
			b[i] = 8;
			cnt++;
		} else if (a[i] == '9'){
			b[i] = 9;
			cnt++;
		} else if (a[i] == '0'){
			b[i] = 0;
			cnt++;
		}
	} 
	sort(b, b + ans);
	for (int i = ans - 1; i >= ans - cnt; i--){
		cout << b[i];
	}
	return 0;
}
