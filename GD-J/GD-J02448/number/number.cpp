#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
char s[N];
int countt[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (s + 1);
	for (int i = 1; s[i] != 0; ++i){
		if (('0' <= s[i]) && (s[i] <= '9')){
			++countt[s[i] - '0'];
		}
	}
	for (int i = 9; i >= 0; --i){
		for (int j = 1; j <= countt[i]; ++j){
			cout << i;
		}
	}
	return 0;
} 
