#include <bits/stdc++.h>
#define ll long long
#define lll __int128

using namespace std;

namespace Read
{
	void read() {}
	template<class T1, class ...T2>
	void read(T1 &n, T2 &...m)
	{
		char c;
		bool sgn = false;
		while (isdigit(c = getchar()) == false)
			if (c == '-') sgn = true;
		n = c ^ 48;
		while (isdigit(c = getchar()))
			n = n * 10 + (c ^ 48);
		if (sgn) n = -n;
		read(m...);
	}
}

using namespace Read;

namespace Solve
{
	bool mbe;
	
	const int N = 1e5;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dpm[4];
	pair<int, int> a[N + 5][5];
	
	void Sol()
	{
		int t;
		read(t);
		while (t--)
		{
			ll ans = 0;
			int n, lmt;
			read(n);
			
			lmt = n >> 1;
			for (int i = 1; i <= 3; ++i)
				while (dpm[i].empty() == false) dpm[i].pop();
				
			for (int i = 1; i <= n; ++i)
			{
				read(a[i][1].first, a[i][2].first, a[i][3].first);
				a[i][1].second = 1, a[i][2].second = 2, a[i][3].second = 3;
				sort(a[i] + 1, a[i] + 4);
			}
			
			for (int i = 1; i <= n; ++i)
			{
				int id = a[i][3].second, dlt = a[i][3].first - a[i][2].first;
				if ((int)dpm[id].size() < lmt)
				{
					dpm[id].push({dlt, i});
					ans += a[i][3].first;
				}
				else
				{
					if (dpm[id].top().first < dlt)
					{
						pair<int, int> u = dpm[id].top();
						dpm[id].pop();
						dpm[id].push({dlt, i});
						ans += a[i][3].first - u.first;
						
						id = a[u.second][2].second;
						dlt = a[u.second][2].first - a[u.second][1].first;
						dpm[id].push({dlt, u.second});
					}
					else
					{
						id = a[i][2].second, dlt = a[i][2].first - a[i][1].first;
						dpm[id].push({dlt, i});
						ans += a[i][2].first;
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
	
	bool med;
}

using namespace Solve;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	cerr << ((double)(&med - &mbe) / (1024.0 * 1024.0)) << endl; 
	Sol();
	return 0;
}
