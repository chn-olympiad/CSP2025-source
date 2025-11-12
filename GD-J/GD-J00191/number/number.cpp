#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 1;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int>a (MAXN);
	int i = 1;
	for (int j = 0; j <= s.size() - 1.; j++) {
		if (s[j] - '0' >= 0 && s[j] - '0' <= 9) {
			a[i++] = s[j] - '0';
		}
	}
	sort(a.begin() + 1, a.begin() + i, cmp);
	for (int j = 1; j <= i - 1; j++) {
		cout << a[j];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
