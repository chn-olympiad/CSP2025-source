#include<bits/stdc++.h> //exp:100pts      
using namespace std;
int cnt[10];
string s;   
int main() {
	freopen("number.in", "r", stdin);  
	freopen("number.out", "w", stdout);
	cin >> s;
	for (auto ch : s)
		if (ch >= '0' && ch <= '9')
			++cnt[ch - '0'];
	for (int i = 9; i >= 0; --i)
		for (int j = 1; j <= cnt[i]; ++j)
			cout << i;
	return 0;
}