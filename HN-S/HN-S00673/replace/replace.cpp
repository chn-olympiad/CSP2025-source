#include <bits/stdc++.h>
using namespace std;
int n, q;
map<string, string> m;
int main()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		m[a] = b;
	}
	while (q--)
	{
		string a, b, diffa = "", diffb = "";
		cin >> a >> b;
		int ans = 0;
		if (m[a] == b) ans++;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
				diffa += a[i], diffb += b[i];
			else if (diffa != "")
			{
				if (m[diffa] == diffb) ans++/*, cout << diffa << " " << diffb << "\n"*/;
				diffa = "", diffb = "";
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

