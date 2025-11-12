#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(char c : s){
		if('0' <= c && c <= '9'){
			int id = c - '0';
			cnt[id]++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		for(int j = 1; j <= cnt[i]; j++) cout << to_string(i);
	}
	return 0;
}
