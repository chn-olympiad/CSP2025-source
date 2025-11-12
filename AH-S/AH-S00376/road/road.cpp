#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>

using namespace std;

constexpr int maxk {11};

array<int, 1000001> u, v, w;
array<array<int, 10001>, maxk> a;
array<int, maxk> c;

int main()
{
	ifstream cin("road.in");
	ofstream cout("road.out");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	long long ans {0}, ansa {0};
	for (int i {1}; i <= m; ++i)
	{
		cin >> u[i] >> v[i] >> w[i];
		ans += w[i];
	}
	for (int i {1}; i <= k; ++i)
	{
		cin >> c[i];
		ansa += c[i];
		for (int j {1}; j <= n; ++j)
		{
			cin >> a[i][j];
			ansa += a[i][j];
		}
	}

	if (k == 0)
		cout << ans << '\n';
	else
	{
		if (n * k >= m)
			cout << ansa << '\n';
		else
		{
			sort(w.begin() + 1, w.begin() + m + 1, greater<int>());
			for (int i {1}; i <= n * k; ++i)
				ans -= w[i];
			cout << ans + ansa << '\n';
		}
	}

	cin.close();
	cout.close();
	return 0;
}