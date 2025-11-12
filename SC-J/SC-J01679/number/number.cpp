#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
vector <char> res;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	
	for (char i : s) {
		if ('0' <= i && i <= '9') {
			res.push_back(i);
		}
	}
	
	sort(res.begin(), res.end(), [](char a, char b){return a > b;});
	
	for (char i : res) {
		cout << i;
	}
	
	return 0;
}