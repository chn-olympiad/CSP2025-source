#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int a[10];

int main()
{
//	freopen("number.in", "w", stdout); // 尝试向number.in中输入数据来对拍 
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			a[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
// fc number.out number1.ans

