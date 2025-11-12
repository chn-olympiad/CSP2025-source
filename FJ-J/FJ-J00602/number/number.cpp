#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	int l = s.length();
	int y = 0;
	for(int i = 0; i < l; i++){
		if('0' <= s[i] && s[i] <= '9') a[y++] = s[i] - '0';
	}
	sort(a, a + y);
	for(int i = y - 1; i >= 0; i--){
		cout << a[i];
	}
	return 0;
} 
