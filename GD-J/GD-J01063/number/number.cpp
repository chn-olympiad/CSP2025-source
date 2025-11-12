#include <bits/stdc++.h>
using namespace std;

const unsigned int Maxn = 10;
unsigned long long L[Maxn];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size() - 1;
	for (int i = 0; i < len; i++){
		if(s[i] <= '9' && s[i] >= '0'){
			L[s[i] - '0']++;
		}
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < L[9 - i]; j++){
			cout << (9 - i);
		}
	}
	return 0;
}
