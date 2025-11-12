#include <bits/stdc++.h> 
#define ll long long 

using namespace std; 

string s; 
int cnt[15]; 

signed main() {
	freopen("number.in", "r", stdin); 
	freopen("number.out", "w", stdout); 
	
	cin >> s; 
	
	for (auto c : s) 
		if ('0' <= c && c <= '9') 
			cnt[c - '0']++; 
	
	for (int i = 9; ~i; --i) 
		for (; cnt[i]; --cnt[i]) printf("%d", i); 
	
	return 0; 
} 