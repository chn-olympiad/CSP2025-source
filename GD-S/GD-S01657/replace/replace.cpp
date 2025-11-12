#include <bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
#define md make_pair
#define gc getchar
#define pc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll res = 0, f = 1; char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = gc();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = gc();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const int N = 2e5 + 5;
const int L = 5e6 + 5;
string s[2][N], t[2];
const int P = 131;
ull hsh[2][L];
ull hshs[2][N];
ull powp[L];
ull Hash(ull *Hsh, int l, int r) { return Hsh[r] - Hsh[l - 1] * powp[r - l + 1]; }
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	powp[0] = 1;
	for (int i = 1; i <= 5e6; i++) powp[i] = powp[i - 1] * P;
	int n = read(), q = read();
	for (int i = 1; i <= n; i++) cin >> s[0][i] >> s[1][i];
	for (int i = 1; i <= n; i++)
	{
		int l = s[0][i].size();
		s[0][i] = ' ' + s[0][i], s[1][i] = ' ' + s[1][i];
		for (int j = 1; j <= l; j++) for (int k = 0; k <= 1; k++) hshs[k][i] = hshs[k][i] * P + s[k][i][j];
	}
	while (q--)
	{
		cin >> t[0] >> t[1];
		int l = t[0].size();
		t[0] = ' ' + t[0], t[1] = ' ' + t[1];
		for (int i = 1; i <= l; i++) for (int j = 0; j <= 1; j++) hsh[j][i] = hsh[j][i - 1] * P + t[j][i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int ls = s[0][i].size() - 1;
//			cout << i << " " << ls << " " << l << endl;
			for (int j = 1; j + ls - 1 <= l; j++)
			{
				int k = j + ls - 1;
//				cout << i << " " << j << " " << k << endl;
//				cout << (Hash(hsh[0], 1, j - 1) == Hash(hsh[1], 1, j - 1)) << endl;
//				cout << (Hash(hsh[0], k + 1, l) == Hash(hsh[1], k + 1, l)) << endl;
//				cout << (Hash(hsh[0], j, k) == hshs[0][i]) << endl;
//				cout << (Hash(hsh[1], j, k) == hshs[1][i]) << endl;
				if (Hash(hsh[0], 1, j - 1) == Hash(hsh[1], 1, j - 1) && Hash(hsh[0], k + 1, l) == Hash(hsh[1], k + 1, l) && Hash(hsh[0], j, k) == hshs[0][i] && Hash(hsh[1], j, k) == hshs[1][i])
				{
					ans++;
					break;
				}
			}
		}
		writech(ans, '\n');
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
