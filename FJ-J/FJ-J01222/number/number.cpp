#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (char c:s){
		if ('0' <= c && '9' >= c){
			v.push_back(c-'0');
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (auto i:v){
		cout << i;
	}
	return 0;
}
