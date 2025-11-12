#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
string a;
string num[maxn];
int cnt = 0;
bool cmp(string a, string b) { return a + b > b + a; }
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; (a[i] >= '0' && a[i] <= '9') || (a[i] >= 'a' && a[i] <= 'z'); i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			num[cnt] = a[i];
			cnt++;
		}
	}
	sort(num, num + cnt, cmp);
	for (int i = 0; i <= cnt; i++)
		cout << num[i];
	return 0;
}
