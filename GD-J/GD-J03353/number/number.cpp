#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	string s;
	cin >> s;
	string numstr;
	for(char c : s){
		if('0'<=c && c<='9') numstr += c;
	}
	sort(numstr.begin(), numstr.end(), greater<char> ());
	cout << numstr;
} 
