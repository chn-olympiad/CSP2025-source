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
	
	const int N = 2e5, L = 5e6;
	
	pair<string, string> s[N + 5];
	string t1, t2, chkh, chked;
	int difl[N + 5], diflen[N + 5];
	
	void Sol()
	{
		int n, q;
		read(n, q);
		for (int i = 1; i <= n; ++i)
		{
			cin >> s[i].first >> s[i].second;
			for (int j = 0; j < (int)s[i].first.size(); ++j)
			{
				if (s[i].first[j] != s[i].second[j])
				{
					difl[i] = j;
					break;
				}
			}
			for (int j = (int)s[i].first.size() - 1; j >= 0; --j)
			{
				
				if (s[i].first[j] != s[i].second[j])
				{
					diflen[i] = j - difl[i] + 1;
					break;
				}
			}
		}
		
		while (q--)
		{
			cin >> t1 >> t2;
			int siz = t1.size(), st = 0, len = 0;
			for (int i = 0; i < siz; ++i)
			{
				if (t1[i] != t2[i])
				{
					st = i;
					break;
				}
			}
			for (int i = siz - 1; i >= 0; --i)
			{
				if (t1[i] != t2[i])
				{
					len = i - st + 1;
					break;
				}
			}
			
			int cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (diflen[i] != len) continue;
				if (difl[i] > st || (int)s[i].first.size() - difl[i] > siz - st) continue;
				if (t1.substr(st, len) != s[i].first.substr(difl[i], len)) continue;
				if (t2.substr(st - difl[i], s[i].first.size()) != s[i].second) continue;
				++cnt;
			}
			printf("%d\n", cnt);
		}
	}
	
	bool med;
}

using namespace Solve;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	Sol();
	return 0;
}
