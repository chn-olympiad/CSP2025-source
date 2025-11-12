#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e6;
string s;
long long cur = 0, num[N];

bool cmp(long long x, long long y)
{
	return x > y;
}

int main()
{
	#ifdef LOCAL
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	#endif
	cin >> s;
	//cout << s.size() << "\n";
	for(int i = 0; i < s.size(); i ++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			num[++cur] = s[i] - '0';
		}
	}
	sort(num + 1, num + cur + 1, cmp);
	for(int i = 1; i <= cur; i ++)
	{
		cout << num[i];
	}
	cout << endl;
	return 0;
}
