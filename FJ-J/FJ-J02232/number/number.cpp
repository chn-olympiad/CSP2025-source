#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> num;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (auto c : s)
		if (c >= '0' && c <= '9')
			num.push_back((int)(c - '0'));
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	for (auto i : num)
		printf("%d", i);
	return 0;
}
