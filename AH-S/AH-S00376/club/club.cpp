#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>

using namespace std;

struct newbie
{
	int d1, d2, d3;
};

array<newbie, 100001> a;

int main()
{
	ifstream cin("club.in");
	ofstream cout("club.out");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	for (cin >> t; t--;)
	{
		int n;
		cin >> n;
		bool type_2 {true}, type_3 {true};
		for (int i {1}; i <= n; ++i)
		{
			cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
			if (a[i].d3 > 0)
				type_2 = type_3 = false;
			else if (a[i].d2 > 0)
				type_2 = false;
		}

		int ans {0};
		if (n == 2)
		{
			ans = a[1].d1 + a[2].d2;
			ans = max(ans, a[1].d1 + a[2].d3);
			ans = max(ans, a[1].d2 + a[2].d1);
			ans = max(ans, a[1].d2 + a[2].d3);
			ans = max(ans, a[1].d3 + a[2].d1);
			ans = max(ans, a[1].d3 + a[2].d2);
		}
		else if (type_2)
		{
			sort(a.begin() + 1, a.begin() + n + 1, [](newbie x, newbie y)
			{
				return x.d1 > y.d1;
			});
			for (int i {1}; i <= n / 2; ++i)
				ans += a[i].d1;
		}
		else if (type_3)
		{
			sort(a.begin() + 1, a.begin() + n + 1, [](newbie x, newbie y)
			{
				return max(x.d1, x.d2) > max(y.d1, y.d2);
			});
			int club1 {0}, club2 {0};
			for (int i {1}; i <= n; ++i)
			{
				int maxa {max(a[i].d1, a[i].d2)};
				if (maxa == a[i].d1 && club1 < n / 2)
				{
					++club1;
					ans += maxa;
				}
				else if (maxa == a[i].d2 && club2 < n / 2)
				{
					++club2;
					ans += maxa;
				}
			}
		}
		else
		{
			sort(a.begin() + 1, a.begin() + n + 1, [](newbie x, newbie y)
			{
				int maxx {max(max(x.d1, x.d2), x.d3)};
				int maxy {max(max(y.d1, y.d2), y.d3)};
				return maxx > maxy;
			});
			int club1 {0}, club2 {0}, club3 {0};
			for (int i {1}; i <= n; ++i)
			{
				int maxa {max(max(a[i].d1, a[i].d2), a[i].d3)};
				if (maxa == a[i].d1 && club1 < n / 2)
				{
					++club1;
					ans += maxa;
				}
				else if (maxa == a[i].d2 && club2 < n / 2)
				{
					++club2;
					ans += maxa;
				}
				else if (maxa == a[i].d3 && club3 < n / 2)
				{
					++club3;
					ans += maxa;
				}
			}
		}

		cout << ans << endl;
		a.fill({0});
	}

	cin.close();
	cout.close();
	return 0;
}