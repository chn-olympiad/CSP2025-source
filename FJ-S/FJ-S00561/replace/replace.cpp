#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5;
typedef long long LL;
const LL base = 131, mod = 1e9 + 9;
typedef pair<LL, LL> PLL;
typedef pair<int, PLL> PIP;
#define x first
#define y second
int n, q;
LL hs[M], ht[M], power[M];
vector<PIP> cr[N];
LL get(string &str)
{
	LL val = 0;
	for (int i = 1; i < (int)str.size(); i ++)val = (val * base % mod + (str[i] - 'a')) % mod;
	return val;
}
LL H(LL h[], int l, int r){return ((h[r] - (h[l - 1] * power[r - l + 1] % mod)) % mod + mod) % mod;}
void work()
{
	string s, t;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	if (s.size() != t.size())
	{
		cout << 0 << '\n';
		return;
	}
	int m = s.size();
	for (int i = 1; i < m; i ++)hs[i] = (hs[i - 1] * base % mod + (s[i] - 'a')) % mod;
	for (int i = 1; i < m; i ++)ht[i] = (ht[i - 1] * base % mod + (t[i] - 'a')) % mod;
	LL res = 0;
	for (int i = 1; i < m; i ++)
	{
		if (hs[i - 1] != ht[i - 1])break;
		for (PIP j : cr[s[i] - 'a'])
		{
			if (i + j.x - 1 >= m)break;
			if (H(hs, i, i + j.x - 1) == j.y.x && H(ht, i, i + j.x - 1) == j.y.y && H(hs, i + j.x, m - 1) == H(ht, i + j.x, m - 1))res ++;
		}
	}
	cout << res << '\n';
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	power[0] = 1;
	for (int i = 1; i < M; i ++)power[i] = power[i - 1] * base % mod;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		string s, t;
		cin >> s >> t;
		s = ' ' + s;
		t = ' ' + t;
		cr[s[1] - 'a'].push_back({s.size() - 1, {get(s), get(t)}});
	}
	for (int i = 0; i < 26; i ++)sort(cr[i].begin(), cr[i].end());
	while (q --)work();
	return 0;
}