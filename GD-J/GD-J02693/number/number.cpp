#include <bits/stdc++.h>
using namespace std;
//1  number
string s;
vector<int> a, ans;
int cnt;
bool cmp (int x, int y) {
	return x > y;
}
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (s[i] == '0') cnt++;
			a.push_back(int(s[i] - '0'));
		}
	}
	if (cnt == a.size()) {
		printf("0");
	}else {
		sort(a.begin(), a.end(), cmp);
		for (auto it : a) printf("%d", it);
	}
	return 0;
}
