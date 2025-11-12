#include <iostream>
#include <string>

namespace preFile
{
	void init()
	{
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

const int maxn = 2e5 + 3;
int n, q, pos1[maxn], pos2[maxn];
std::string s1[maxn], s2[maxn];

namespace B
{
	void Main()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < s1[i].size(); j++)
				if (s1[i][j] == 'b')
					pos1[i] = j;
			for (int j = 0; j < s2[i].size(); j++)
				if (s2[i][j] == 'b')
					pos2[i] = j;
		}
		while (q--)
		{
			std::string t1, t2;
			std::cin >> t1 >> t2;
			if (t1.size() != t2.size())
			{
				std::cout << "0\n";
				continue;
			}
			int p1, p2;
			for (int j = 0; j < t1.size(); j++)
				if (t1[j] == 'b')
					p1 = j;
			for (int j = 0; j < t2.size(); j++)
				if (t2[j] == 'b')
					p2 = j;
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (pos1[i] - pos2[i] == p1 - p2 &&
					pos1[i] <= p1 && pos2[i] <= p2 &&
					s1[i].size() - pos1[i] <= t1.size() - p1 &&
					s2[i].size() - pos2[i] <= t2.size() - p2)
						ans++;
			std::cout << ans << '\n';
		}
	}
}

namespace small
{
	void Main()
	{
		while (q--)
		{
			int ans = 0;
			std::string t1, t2;
			std::cin >> t1 >> t2;
			if (t1.size() != t2.size())
			{
				std::cout << "0\n";
				continue;
			}
			for (int j = 1; j <= n; j++)
			{
				for (int i = 0; i < t1.size(); i++)
				{
					std::string t = t1.substr(i, s1[j].size());
					if (t == s1[j])
					{
						std::string tmp = t1;
						for (int k = 0; k < s2[j].size(); k++)
							tmp[k + i] = s2[j][k];
						if (tmp == t2)
							ans++;
					}
				}
			}
			std::cout << ans << '\n';
		}
	}
}

int main()
{
	preFile::init();
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++)
		std::cin >> s1[i] >> s2[i];
	if (n <= 100)
		small::Main();
	else
		B::Main();
	return 0;
}