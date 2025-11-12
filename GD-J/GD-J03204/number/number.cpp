#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int len;
vector<int> v;	
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for(int i = 0; i < len; i++) {
		if(isdigit(s[i])) {
			int num = s[i] - '0';
			v.push_back(num);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i : v) cout << i;
	return 0;
} 
