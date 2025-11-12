#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string st[200005][2],s,t;
	for (int i = 1; i <= n; i++)
		cin >> st[i][0] >> st[i][1];
	for (int j = 1; j <= q; j++)
	{
		cin >> s >> t;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int pos = s.find(st[i]);
			if (pos == -1)
				continue;
			if (s.substr(0,pos) + st[i] + s.substr(pos + st[i].size()) == t)
				cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}
