#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6+5;
string s;
int x[N], num;
bool cmp(const int &x, const int &y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] <= '9' && s[i] >= '0')
			x[++num] = s[i] - '0';
	sort(x+1, x+num+1, cmp);
	for (int i = 1; i <= num; i++) cout << x[i];
	return 0;
}
