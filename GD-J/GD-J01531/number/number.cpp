#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> v;
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			v.push_back(s[i] - '0');
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size();i++){
		cout << v[i];
	}
	return 0;
} 

