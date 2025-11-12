#include <bits/stdc++.h>

using namespace std;

int a[15];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			int n = s[i]-'0';
			a[n]++;
		}
	}
	
	for (int i = 9; i >= 0; i--){
		for (int j = 1; j <= a[i]; j++){
			cout << i;
		}
	}
	return 0;
} 
