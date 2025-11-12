#include <iostream>
#include <cstdio> 
#include <string>
using namespace std;
int cnt[128];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)cnt[s[i]]++;
	for (char i = '9'; i >= '0'; i--){
		for (int j = 0; j < cnt[i]; j++)cout << i;
	}
	return 0;
} 
