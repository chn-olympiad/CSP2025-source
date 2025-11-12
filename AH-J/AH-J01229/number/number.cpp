#include <bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int lengh = s.size();
	for(int i = 0; i < lengh; ++i){
		if(s[i] >= '0' && s[i] <= '9'){
			int x = s[i] - '0';
			a[x]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; ++j){
			cout << i;
		}
	}
	return 0;
}
