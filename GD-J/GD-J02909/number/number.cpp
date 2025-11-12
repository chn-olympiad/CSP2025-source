#include <bits/stdc++.h>
using namespace std;
string s;
int number[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//¼ÆÊý 
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(0 <= s[i] - '0' && s[i] - '0' <= 9){
			int x = s[i] - '0';
			number[x]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= number[i]; j++){
			cout << i;
		}
	}
	return 0;
} 
