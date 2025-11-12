#include <iostream>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int bucket[15];
	for (int i = 0; i < 15; i++){
		bucket[i] = 0;
	}
	int len = s.length();
	int index = 0;
	for (int i = 0; i < len; i++){
		if ('0' <= s[i] && s[i] <= '9'){
		index = s[i] - '0';
		bucket[index]++;
		}
	}
	for (int m = 9; m >= 0; m--){
		while (bucket[m] > 0){
			cout << m;
			bucket[m]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
