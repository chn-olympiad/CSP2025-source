#include <bits/stdc++.h>
using namespace std;
int b[15];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int l = a.size();
	for(int i = 0; i < l; i++){
		if('0' <= a[i] <= '9'){
			b[a[i] - '0']++;	
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= b[i]; j++){
			cout << i;
		}
	}
	return 0;
}

