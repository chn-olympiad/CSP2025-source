#include <bits/stdc++.h>
#include <ext/rope>
// #define int long long
using namespace std;
using __gnu_cxx::crope;
pair<crope, crope> p[200005];
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i{1}; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		p[i].first = a.c_str();
		p[i].second = b.c_str();
	}
	while (q--)
	{
		int tot{};
		string a, b;
		cin >> a >> b;
		crope s{a.c_str()}, t{b.c_str()};
		if (s.size() != t.size())
			goto end;
		for (int i{1}; i <= n; i++)
		{
			int f{s.find(p[i].first.c_str())}, g{t.find(p[i].second.c_str())};
			while (~f && ~g && f != g)
				if (f < g)
					f = s.find(p[i].first.c_str(), f + 1);
				else
					g = t.find(p[i].second.c_str(), g + 1);
			if (f == -1 || g == -1)
				continue;
			crope news{s.substr(0, f) + p[i].second + s.substr(f + p[i].second.size(), 5000006)};
//			cout << news.c_str() << ' ' << s.c_str() << ' ' << t.c_str() << endl;
			tot += (news == t);
		}
		end:;
		cout << tot << endl;
	}
	return 0;
}

