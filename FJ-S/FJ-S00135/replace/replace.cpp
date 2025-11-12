#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 1;
pair<string, string> s[maxn];
string t, ts;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i].first >> s[i].second;
	}
	while(q--)
	{
		ll ans = 0;
		cin >> t >> ts;
		for(int i = 1; i <= n; i++)
		{
			int pos = t.find(s[i].first);
			if(pos == -1)
			{
				continue;
			}
			string x = t.substr(0, pos), y = s[i].second, z = t.substr(pos + s[i].first.size());
			string end = x + y + z;
			if(end == ts)
			{
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
