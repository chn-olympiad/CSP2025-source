#include <bits/stdc++.h>
using namespace std;
string str;
int out_ans[1000005], len_ans, p;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			len_ans++;
			out_ans[len_ans] = (str[i] - '0');
		}
	}
	sort(out_ans + 1, out_ans + len_ans + 1);
	if(out_ans[len_ans] == 0) {
		cout << 0;
		return 0;
	}
	for(int i = len_ans; i >= 1; i--) {
		cout << out_ans[i];
	}
	return 0;
}
