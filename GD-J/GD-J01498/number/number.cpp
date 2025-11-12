#include<bits/stdc++.h>
using namespace std;
vector<int> v; 
int main() {
	freopen("number4.in", "r", stdin);
	freopen("number4.out", "w", stdout);
	string s;
	cin >> s;
	for(char c : s) {
		if(c >= '0' && c <= '9')
			v.push_back(c - '0');
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i : v) cout << i;
	return 0;
}
