#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int N[15];
	memset(N,0,sizeof(N));
	cin >> s; 
	for(char c : s) {
		if(isdigit(c)) {
			N[c-'0']++;
		}
	}
	for(int i = 9;i >= 0;i--) {
		for(int j = 1;j <= N[i];j++) {
			cout << i;
		}
	}
	return 0; 
}
