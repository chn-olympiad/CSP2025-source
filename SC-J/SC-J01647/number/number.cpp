#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int num[N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str;
	cin >> str;
	int len = str.size();
	str = ' ' + str;
	int cur = 0;
	for (int i = 1; i <= len; i++) {
		if (isdigit(str[i])) {
			num[++cur] = (str[i] - '0');
		}
	}
	stable_sort(num + 1, num + cur + 1, cmp);
	for (int i = 1; i <= cur; i++) {
		cout << num[i];
	}
	return 0;
}