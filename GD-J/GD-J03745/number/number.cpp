#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int nums[10] = {0};
	cin >> s;
	for (char ch : s) {
		if (ch == '0') nums[0]++;
		else if (ch == '1') nums[1]++;
		else if (ch == '2') nums[2]++;
		else if (ch == '3') nums[3]++;
		else if (ch == '4') nums[4]++;
		else if (ch == '5') nums[5]++;
		else if (ch == '6') nums[6]++;
		else if (ch == '7') nums[7]++;
		else if (ch == '8') nums[8]++;
		else if (ch == '9') nums[9]++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= nums[i]; j++) {
			cout << i;
		}
	}
	return 0;
}

