#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;
char s[maxn];
int n;
int num[17];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	n = strlen(s);
	bool flag = 0;
	for(int i = 0; i < n; i ++) {
		char x = s[i];
		if('0' <= x && x <= '9' && x != '0') flag = 1;
		if('0' <= x && x <= '9') num[x - '0'] ++;
	}
	if(flag == 0) {
		cout << "0";
		return 0;
	}
	for(int i = 9; i >= 0; i --) {
		while(num[i] --) cout << i;
	}
	cout << endl;
	return 0;	
} 