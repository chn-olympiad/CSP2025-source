//GZ-S00144 幸进尧 贵阳市云城中学
#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 1 << 20;
char buff[SIZE], *ptr1, *ptr2;

#define gc() (ptr1 == ptr2 && (ptr2 = (ptr1 = buff) + fread(buff, 1, SIZE, stdin), ptr1 == ptr2) ? EOF : *ptr1++)
#define dg(c) (c >= '0' && c <= '9')
#define sp(c) (c <= 32 || c == 127)

int readI()
{
	int x = 0, c = gc();
	while (!dg(c)) c = gc();
	while (dg(c)) x = x * 10 + (c & 15), c = gc();
	return x;
}

string readS()
{
	string s; char c = gc();
	while (sp(c)) c = gc();
	while (!sp(c)) s.push_back(c), c = gc();
	return s;
}

#undef gc
#undef dg
#undef sp

constexpr int N = 5e6 + 5, M = 26;
constexpr int base1 = 133, MOD1 = 1e9 + 7;
constexpr int base2 = 131, MOD2 = 1e9 + 9;

map <array <int, 4>, array <int, 2>> rot;
int tot, son[N][M], vis[N];
vector <int> idx[N];

void insert(int id, string s1, string s2)
{
	int n = s1.size();
	int l = 0, r = n- 1;
	while (s1[l] == s2[l]) ++l;
	while (s1[r] == s2[r]) --r;
	array <int, 4> h{0, 0, 0, 0};
	for (int i = l; i <= r; i ++)
	{
		h[0] = (1ll * h[0] * base1 % MOD1 + s1[i]) % MOD1;
		h[1] = (1ll * h[1] * base2 % MOD2 + s1[i]) % MOD2;
		h[2] = (1ll * h[2] * base1 % MOD1 + s2[i]) % MOD1;
		h[3] = (1ll * h[3] * base2 % MOD2 + s2[i]) % MOD2;
	}
	if (!rot.count(h)) rot[h] = {tot + 1, tot + 2}, tot += 2;
	
	int p = rot[h][0];
	for (int i = l - 1; ~i; i --)
	{
		int& q = son[p][s1[i] - 'a'];
		if (!q) q = ++tot; p = q;
	}
	idx[p].push_back(id), p = rot[h][1];
	for (int i = r + 1; i < n; i ++)
	{
		int& q = son[p][s1[i] - 'a'];
		if (!q) q = ++tot; p = q;
	}
	idx[p].push_back(id);
}

int query(int id, string s1, string s2)
{
	int n = s1.size();
	int l = 0, r = n- 1;
	while (s1[l] == s2[l]) ++l;
	while (s1[r] == s2[r]) --r;
	array <int, 4> h{0, 0, 0, 0};
	for (int i = l; i <= r; i ++)
	{
		h[0] = (1ll * h[0] * base1 % MOD1 + s1[i]) % MOD1;
		h[1] = (1ll * h[1] * base2 % MOD2 + s1[i]) % MOD2;
		h[2] = (1ll * h[2] * base1 % MOD1 + s2[i]) % MOD1;
		h[3] = (1ll * h[3] * base2 % MOD2 + s2[i]) % MOD2;
	}
	if (!rot.count(h)) return 0;
	
	int p = rot[h][0], res = 0;
	for (int u : idx[p]) vis[u] = id;
	for (int i = l - 1; ~i; i --)
	{
		int& q = son[p][s1[i] - 'a'];
		if (!q) break; p = q;
		for (int u : idx[p]) vis[u] = id;
	}
	p = rot[h][1];
	for (int u : idx[p]) res += vis[u] == id;
	for (int i = r + 1; i < n; i ++)
	{
		int& q = son[p][s1[i] - 'a'];
		if (!q) break; p = q;
		for (int u : idx[p]) res += vis[u] == id;
	}
	return res;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n = readI(), q = readI();
	while (n --)
	{
		string s1 = readS(), s2 = readS();
		if (s1 != s2) insert(n, s1, s2);
	}
	memset(vis, -1, sizeof(vis));
	while (q --)
	{
		string t1 = readS(), t2 = readS();
		if (t1.size() != t2.size()) puts("0");
		else printf("%d\n", query(q, t1, t2));
	}
	
	return 0;
}
