#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	string str[n+10][2], st[n+10][2];
	for(int i = 1;i <= n;i++){
		cin >> str[i][1] >> str[i][2];
	}
	for(int i = 1;i <= q;i++){
		cin >> st[i][1] >> str[i][2];
	}
	return 0;
}
