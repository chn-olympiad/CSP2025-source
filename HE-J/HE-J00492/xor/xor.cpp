#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k;
const int N = 1e3 + 5;
bool a[N][22];
int s[N][22];
int ll[22];
pair<int, int> ans[N * N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int nw;
		cin >> nw;
		for (int j = 21; j >= 1 && nw; j--)
		{
			a[i][j] = (nw % 2);
			nw /= 2;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 21; j >= 1; j--)
			s[i][j] = s[i - 1][j] + a[i][j];
	int cnt = 0;
	int lst_j = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			for (int l = 21; l >= 1; l--)
				ll[l] = s[j][l] - s[i - 1][l];
			for (int l = 21; l >= 1; l--)
				ll[l] %= 2;
			int L = 0;
			for (int l = 21, pw = 1; l >= 1; l--, pw *= 2)
				L += pw * ll[l];
			if (L == k) ans[++cnt] = {i, j};
		}
	}
	sort(ans + 1, ans + cnt + 1);
	int anss = 0;
	for (int i = 1; i <= cnt; i++)
	{
		anss++;
		int l = ans[i].first, r = ans[i].second;
		while (ans[i + 1].first <= r) i++;
	}
	cout << anss << endl;
	return 0; 
}

