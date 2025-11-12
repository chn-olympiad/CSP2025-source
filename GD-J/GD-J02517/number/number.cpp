#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long> popss(string str) {
	vector<long> ans(10, 0);
	for(int i = 0;i < str.length();i++) {
		if('0' <= str[i] && str[i] <= '9') {
			ans[str[i] - '0']++;
		}
	}
	return ans;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<long> num = popss(s);

	for(int i = num.size() - 1;i >= 0;i--) {
		for(long j = 0;j < num[i];j++) cout << i;
	}
	return 0;
}

