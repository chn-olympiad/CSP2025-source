#include <bits/stdc++.h>

using namespace std; 

string s, t; 

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	
	cin >> s;
	
	for (int i = 0; i < (int)s.size(); i++) 
		if (isdigit(s[i])) 
			t += s[i];
	
	sort(t.begin(), t.end(), greater<char>());
	
	if (t[0] == '0') cout << "0";
	else cout << t;
	
	return 0;
}