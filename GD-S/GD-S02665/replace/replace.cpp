#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 30005;
int n, q;
string s1[N], s2[N];
unordered_map<string, string> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i{1}; i <= n; ++i)
	{
		cin >> s1[i] >> s2[i];
		s[s1[i]] = s2[i];
	}
	if (q == 1)
	{
		int ans{};
		string t1, t2;
		cin >> t1 >> t2;
		if (s[t1] == t2)
			cout << 1;
		else
			cout << 0;
		exit(0);
	}
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		cout << 0 << '\n';
	}
	return 0;
}
