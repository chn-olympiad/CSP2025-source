#include<bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, q, l[N], st[N], ed[N], flg, ans; string s[N][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	if(n > 10000)
	{
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i][0] >> s[i][1]; l[i] = s[i][0].length();
			for(int j = 0; j < l[i]; j++) if(s[i][0][j] == 'b') st[i] = j;
			for(int j = 0; j < l[i]; j++) if(s[i][1][j] == 'b') ed[i] = j;
		}
		while(q--)
		{
			cin >> s[0][0] >> s[0][1]; ans = n, l[0] = s[0][0].length(); if(s[0][1].length() != l[0]) {cout << 0 << endl; continue; }
			for(int j = 0; j < l[0]; j++) if(s[0][0][j] == 'b') st[0] = j;
			for(int j = 0; j < l[0]; j++) if(s[0][1][j] == 'b') ed[0] = j;
			for(int i = 1; i <= n; i++) if(ed[i] - st[i] != ed[0] - st[0] || st[0] < st[i] || l[i] - ed[i] > l[0] - ed[0]) ans--;
			cout << ans << endl;
		}
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1]; st[i] = l[i] = s[i][0].length();
		for(int j = 0; j < l[i]; j++) if(s[i][0][j] != s[i][1][j]) {if(st[i] == l[i]) st[i] = j; ed[i] = j; }
	}
	while(q--)
	{
		cin >> s[0][0] >> s[0][1]; st[0] = l[0] = s[0][0].length(), ed[0] = flg = ans = 0;
		if(s[0][1].length() != l[0]) {cout << 0 << endl; continue; }
		for(int j = 0; j < l[0]; j++) if(s[0][0][j] != s[0][1][j]) {if(st[0] == l[0]) st[0] = j; ed[0] = j; }
		for(int i = 1; i <= n; i++)
		{
			if(st[i] == l[i] || ed[i] - st[i] != ed[0] - st[0] || st[0] < st[i] || l[i] - ed[i] > l[0] - ed[0]) continue; flg = 1;
			for(int j = st[0]; j <= ed[0]; j++)
				if(s[i][0][j - st[0] + st[i]] != s[0][0][j] || s[i][1][j - st[0] + st[i]] != s[0][1][j]) {flg = 0; break; }
			ans += flg;
		}
		cout << ans << endl;
	}
	
	return 0;
}