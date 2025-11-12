#include <bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
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
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
int cnt[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s; cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++)
	{
		if (s[i] < '0' || s[i] > '9') continue;
		cnt[s[i] - '0']++;
	}
	bool flag = false;
	for (int i = 9; i >= 0; i--)
	{
		if (!cnt[i]) continue;
		if (i >= 1)
		{
			flag = true;
			for (int j = 1; j <= cnt[i]; j++) write(i);
		}
		else if (flag)
		{
			for (int j = 1; j <= cnt[i]; j++) write(i);
		}
	}
	return 0;
}

