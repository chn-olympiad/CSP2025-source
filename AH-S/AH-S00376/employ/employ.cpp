#include <array>
#include <fstream>
#include <iostream>

using namespace std;

constexpr int mod {998244353}, maxn {501};

array<char, maxn> s;
array<int, maxn> c;

int main()
{
	ifstream cin("employ.in");
	ofstream cout("employ.out");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i {1}; i <= n; ++i)
		cin >> s[i];
	int cntc {n};
	for (int i {1}; i <= n; ++i)
	{
		cin >> c[i];
		if (c[i] == 0)
			--cntc;
	}
	if (m == n)
		cout << 0 << '\n';
	else
	{
		unsigned long long p {1};
		for (int i {2}; i <= cntc; ++i)
			p = p * i % mod;
		cout << p << '\n';
	}

	cin.close();
	cout.close();
	return 0;
}