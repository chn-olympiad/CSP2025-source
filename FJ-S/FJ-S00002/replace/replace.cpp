#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, q, ans;
string p[N][3];
string a, b, t;
vector<int> get(string s, string a)
{
	vector<int> v;
	v.clear();
	for (int i = 0; i <= s.size() - a.size(); i++)
	{
		if (s.substr(i, a.size()) == a)
		{
			v.push_back(i);
		}
	}
	return v;
}
bool find(string s, string a)
{
	for (int i = 0; i <= s.size() - a.size(); i++)
	{
		if (s.substr(i, a.size()) == a)
		{
			return true;
		}
	}
	return false;
}
string replace2(string s, int idx, int sz, string str)
{
	string ans = s;
	for (int i = idx; i < idx + sz; i++)
	{
		ans[i] = str[i - idx];
	}
	return ans;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i][1] >> p[i][2];
	}
	while (q--)
	{
		ans = 0;
		cin >> a >> b;
		for (int i = 1; i <= n; i++)
		{
			string s = p[i][1];
			if (find(a, s))
			{
				vector<int> v = get(a, s);
				for (int j = 0; j < v.size(); j++)
				{
					if (replace2(a, v[j], p[i][2].size(), p[i][2]) == b)
					{
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
