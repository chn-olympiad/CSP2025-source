#include <bits/stdc++.h>
using namespace std;
map<string, string> re;
int n, q, ans;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		re[s1] = s2;
	}
	while (q--)
	{
		ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.length();
		for (int i = 0; i <= len; i++) //0~i
		{
			for (int j = i; j <= len; j++) //j~n
			{
				string t = t1.substr(i, j - i);
				auto it = re.find(t);
				if (it != re.end())
				{
					string tt = t1.substr(0, i) + re[t] + t1.substr(j, len - j + 1);
					if (tt == t2)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}
//O(n + q(L^2*nlogn)) 

