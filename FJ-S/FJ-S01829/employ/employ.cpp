#include <iostream>
#include <algorithm>

namespace preFile
{
	void init()
	{
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

const int mod = 998244343;
const int maxn = 503;
int n, m, c[maxn], a[maxn], cnt0;
std::string s;

int main()
{
	preFile::init();
	std::cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++)
		std::cin >> c[i];
	for (int i = 1; i <= n; i++)
		a[i] = i;
	int ans = 0;
	do
	{
		int fail = 0;
		for (int i = 1; i <= n; i++)
			if (c[a[i]] <= fail || s[i] == '0')
				fail++;
		if (fail <= n - m)
			ans++;
	}
	while (std::next_permutation(a + 1, a + n + 1));
	std::cout << ans;
	return 0;
}