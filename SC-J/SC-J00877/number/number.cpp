#include <bits/stdc++.h>
#define int long long
using namespace std;

vector <int> apr;
string S;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
//	freopen("number4.in", "r", stdin);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> S;
	for(auto i : S) {
		if('0' <= i && '9' >= i) apr.emplace_back(i - '0');
	}
	sort(apr.begin(), apr.end(), cmp);
	
	for(int i = 0; i < apr.size(); i ++) {
		cout << apr[i];
	}
	return 0;
}
