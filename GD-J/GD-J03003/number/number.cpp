#include <bits/stdc++.h>
using namespace std;
int book[12];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= '0' && s[i] <= '9'){
			book[s[i]-'0']++;
		}
	}
	for (int i = 9; i >= 0; ){
		if (book[i] != 0){
			cout << i;
			book[i]--;
		} else {
			i--;
		}
	}
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
