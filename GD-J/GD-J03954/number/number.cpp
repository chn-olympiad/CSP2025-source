#include <bits/stdc++.h>
using namespace std;
int a[12];
int main(){
	char s[1000005];
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < strlen(s); i++){
		if (s[i] > 48 && s[i] <= 57) {
			a[s[i]-48]++;
		}
	}
	for (int i = 9; i >=0 ; i--){
		for(int j = 0; j < a[i]; j++) cout <<i;
	}
	return 0;
} 
