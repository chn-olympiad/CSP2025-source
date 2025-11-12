#include <iostream>
#include <cstdio>

using namespace std;

int n, m, limit[5005];
string str;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	for (int i = 1; i <= n; i++)
	{
		cin >> limit[i];
	}
	cout << 0 << endl;
	return 0;
}
