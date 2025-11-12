#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
long long n, q, ans, k;
string t1, t2, t;
struct str
{
	string s;
	long long c;
}a[N][3];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][1].s >> a[i][2].s;
		a[i][1].c = 0;
		for (int j = 0; j < a[i][1].s.size(); j++)
		{
			if (a[i][1].s[j] != a[i][2].s[j]) a[i][1].c++;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> t1 >> t2;
		k = 0;
		for (int j = 0; j < t1.size(); j++)
		{
			if (t1[j] != t2[j]) k++;
		}
		ans = 0;
		for (int j = 1; j <= n; j++)
		{
			if (t1.size() == t2.size() && t1.find(a[j][1].s) != string::npos && a[i][1].c == k && t2.find(a[j][2].s) != string::npos && t1.find(a[j][1].s) == t2.find(a[j][2].s))
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
