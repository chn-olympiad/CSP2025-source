#include <bits/stdc++.h>
using namespace std;

string number; 

int main() {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> number;
	sort(number.begin() , number.end() , greater<char>());
	int len = number.size();
	for(int i = 0 ; i < len ; i++) {
		if('0' <= number[i] && number[i] <= '9') {
			cout << number[i];
		}
	}
	return 0;
}

