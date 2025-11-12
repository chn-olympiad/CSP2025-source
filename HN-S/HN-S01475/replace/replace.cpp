#include <bits/stdc++.h>

using namespace std;
const int N = 10010;

int n, Q;
string x[N], y[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> Q;
	for (int i = 1; i <= n; i ++ )
		cin >> x[i] >> y[i];

	while (Q -- )
	{
		int ans = 0;
		string a, b; cin >> a >> b;
		if (a.size() != b.size())
		{
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 0; j + (int)x[i].size() - 1 < (int)a.size(); j ++ )
				if (a.substr(j, (int)x[i].size()) == x[i] 
				 && b.substr(j, (int)x[i].size()) == y[i]
				 && a.substr(0, j) == b.substr(0, j)
				 && a.substr(j + (int)x[i].size()) == b.substr(j + (int)x[i].size()))
					ans ++ ;
		}
		
		cout << ans << endl;
	}

	return 0;
}

