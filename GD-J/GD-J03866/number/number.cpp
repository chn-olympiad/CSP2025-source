#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll number[15];
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	ll len = s.size();
	for (ll i = 0 ; i < len ; i++){
		if (s[i] == '0'){
			number[0]++;
		}
		if (s[i] == '1'){
			number[1]++;
		}
		if (s[i] == '2'){
			number[2]++;
		}
		if (s[i] == '3'){
			number[3]++;
		}
		if (s[i] == '4'){
			number[4]++;
		}
		if (s[i] == '5'){
			number[5]++;
		}
		if (s[i] == '6'){
			number[6]++;
		}
		if (s[i] == '7'){
			number[7]++;
		}
		if (s[i] == '8'){
			number[8]++;
		}
		if (s[i] == '9'){
			number[9]++;
		}
	}
	for (int i = 9 ; i >= 0 ; i--){
		while(number[i]--){
			cout << i;
		}
	}
	return 0;
}
