#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int numTuple, numQuery;
	cin >> numTuple >> numQuery;
	vector<pair<string, string>> tuples(numTuple);
	for (auto &elem : tuples)
	{
		cin >> elem.first >> elem.second;
	}
	
	while (numQuery--)
	{
		string source, target;
		cin >> source >> target;
		if (source.length() != target.length())
		{
			cout << 0 << endl;
			continue;
		}
		int cnt = 0;
		for (auto replace : tuples)
		{
			for (int i = 0; i + replace.first.length() <= source.length(); i++)
			{
				if (source.substr(i, replace.first.length()) == replace.first)
				{
					if (replace.second == target.substr(i, replace.first.length()))
					{
						if (source.substr(0, i) == target.substr(0, i))
						{
							if (source.substr(i + replace.first.length(), source.length() - i - replace.first.length()) == target.substr(i + replace.first.length(), source.length() - i - replace.first.length()))
								cnt++;
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
