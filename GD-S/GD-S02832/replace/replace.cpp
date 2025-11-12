#include<bits/stdc++.h>
using namespace std;
map<int, bool> mp;
int solve()
{
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		string a, b; cin >> a >> b;
		int st; for (int i = 0; i < a.size(); i++) if (a[i] == 'b') st = i;
		int ed; for (int i = 0; i < b.size(); i++) if (b[i] == 'b') ed = i;
		mp[st-ed] = 1;
	}
	for (int i = 1; i <= q; i++)
	{
		string a, b; cin >> a >> b;
		int st; for (int i = 0; i < a.size(); i++) if (a[i] == 'b') st = i;
		int ed; for (int i = 0; i < b.size(); i++) if (b[i] == 'b') ed = i;
		if(mp[st-ed] == 1) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
