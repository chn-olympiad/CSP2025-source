#include <iostream>
#include <algorithm>
using namespace std;

const long long M = 998244353;

int c[510];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	long long a = n;
	for (int i = 1; i <= n; i++)
		if (c[i] == 0) a--;
	cout << a << endl;
	long long ans = 1;
	for (int i = 1; i <= m; i++)
	{
		ans = ans * a % M;
		a--;
	}
	cout << ans << endl;
	return 0;
}
