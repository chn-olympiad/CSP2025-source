#include <iostream>
#include <string>
using namespace std;

int n, q;
struct instead{
	string a, b;
} replace[200005];

int ans;

int fc(string a, string b)
{
	int p = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (p > b.size() - 1)
		{
			return i - p + 1;
		}
		if (a[i] == b[p])
		{
			p++;
		}
		else p = 0;
	}
	return -1;
}

bool prefc(string a, string b, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

bool subfc(string a, string b, int num)
{
	for (int i = a.size(); i > num; i--)
	{
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> replace[i].a >> replace[i].b;
	}
	
	for (int i = 1; i <= q; i++)
	{
		ans = 0;
		string x, y;
		cin >> x >> y;
		for (int j = 1; j <= n; j++)
		{
			int sy_1 = fc(x, replace[j].a);
			int sy_2 = fc(y, replace[j].b);
//			cout << sy_1 << " " << sy_2 << endl;
			if (sy_1 == sy_2 && sy_1 != -1 && prefc(x, y, sy_1) && subfc(x, y, sy_1 + replace[j].a.size() - 1))
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

