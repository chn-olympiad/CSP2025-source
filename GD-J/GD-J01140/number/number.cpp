#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e6 + 10;
string s;
int nums[N], cur;
bool cmp(int x, int y)
{
	return x > y;
}
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			nums[++cur] = s[i] - '0';
		}
	}
	sort(nums + 1, nums + cur + 1, cmp);
	for (int i = 1; i <= cur; ++i)
	{
		cout << nums[i];
	}
	return 0;
}
