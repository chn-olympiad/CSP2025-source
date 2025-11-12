#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int N = 200010;
const int B = 231;

int n, m, cnt;
int L[N], R[N];
string s[N], t[N], a, b;

bool check(int id, int l, int r)
{
	if (L[id] > R[id] || R[id] - L[id] != r - l || s[id].length() - R[id] > a.length() - r || L[id] > l) return 0;
	for (int i = l - L[id], j = 0; j < s[id].length(); i++, j++)
		if (a[i] != s[id][j] || b[i] != t[id][j]) return 0;
	return 1;
}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i] >> t[i];
		L[i] = 0;
		R[i] = s[i].length() - 1;
		while (L[i] >= 0 && s[i][L[i]] == t[i][L[i]]) L[i]++;
		while (R[i] < s[i].length() && s[i][R[i]] == t[i][R[i]]) R[i]--;
	}
	while (m--)
	{
		cin >> a >> b;
		if (a.length() != b.length())
		{
			printf("0\n");
			continue;
		}
		int l = 0, r = a.length() - 1, ans = 0;
		while (a[l] == b[l]) l++;
		while (a[r] == b[r]) r--;
		for (int i = 1; i <= n; i++)
			if (check(i, l, r)) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
