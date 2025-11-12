#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int a[50] = {};
	int n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9') a[int(s[i] - '0')]++;
	}
	bool e = true;
	for(int i = 9; i >= 0; i--){
		if(a[i] != 0 && i != 0) e = false;
	}
	if(e){
		cout << 0;
		return 0;
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++) cout << i;
	}
	return 0;
}
