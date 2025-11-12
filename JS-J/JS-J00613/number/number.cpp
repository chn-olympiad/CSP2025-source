#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1e6 + 5;
int a[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cur = 0, l = s.size();
	for (int i = 0; i < l; ++i)
	{
		if ('0' <= s[i] && s[i] <= '9') a[++cur] = s[i] - '0';
	}
	sort(a + 1, a + cur + 1, greater<int>());
	for (int i = 1; i <= cur; ++i) cout << a[i];
	cout << endl;
	return 0;
}
