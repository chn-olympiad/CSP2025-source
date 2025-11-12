#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define endl "\n"

string str;
int num[11] = {0};

void print(int x, int n) {
	while (n--) {
		cout << (char)(x + '0');
	}
	return ;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		if ('0' <= str[i] && str[i] <= '9') {
			int temp = str[i] - '0';
			++num[temp];
		}
	}

	bool flag = false;
	for (int i = 9; i >= 0; --i) {
		if (i == 0 && flag == false) {
			cout << "0" << endl;
		}
		else {
			print(i, num[i]);
			if (num[i] > 1) flag = true;
		}
	}
//	cout << num[0] << endl;

	return 0;
}
