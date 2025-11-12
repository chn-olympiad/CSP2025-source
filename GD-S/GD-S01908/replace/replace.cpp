#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 5e6 + 5;
const int BASE = 19;
const int MOD = 4999999;
int Qpow(int a, int b) {int base = a, ans = 1; while (b) {if (b & 1) ans = 1ll * ans * base % MOD; base = 1ll * base * base % MOD; b >>= 1;} return ans;}
int Inv(int a) {return Qpow(a, MOD - 2);}
const int C = 101;

int Hsh(string s)
{
	int res = 0, t = 1;
	for (unsigned i = 0; i < s.size(); i++)
		res = (res + 1ll * t * (s[i] - 'a') % MOD) % MOD, t = 1ll * t * BASE % MOD;
	return res;
}

int Calc(string s, string t)
{
	return (Hsh(s) + 1ll * C * ((1ll << 30) * (Hsh(t) ^ 1738) % MOD) % MOD) % MOD;
}

bool Check(string s)
{
	int cnt = 0;
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (s[i] == 'b')
			cnt++;
		else if (s[i] != 'a')
			return false;
	}
	return cnt == 1;
}

int Find(string s)
{
	for (unsigned i = 0; i < s.size(); i++)
		if (s[i] == 'b')
			return i;
	return 0;
}

//int ct[MAXM << 1];
//
//int Lowbit(int x) {return x & -x;}
//void Update(int x, int n) {for (int i = x; i <= n; i += Lowbit(i)) ct[i]++;}
//int Query(int x) {int ans = 0; for (int i = x; i; i -= Lowbit(i)) ans += ct[i]; return ans;}

string s[MAXN][2], t[MAXN][2];
int c[MAXM];
int a[MAXM], b[MAXM];

//struct node
//{
//	string sa, sb;
//	int L, R, opt;
//	bool operator < (const node &x) const
//	{
//		if (L == x.L)
//			return opt < x.opt;
//		return L < x.L;
//	}
//}p[MAXN << 1];

int main()
{
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	bool flg_B = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
		flg_B &= (Check(s[i][0]) && Check(s[i][1]));
//		printf("vv = %d\n", Calc(s[i][0], s[i][1]));
		c[Calc(s[i][0], s[i][1])]++;
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> t[i][0] >> t[i][1];
		flg_B &= (Check(t[i][0]) && Check(t[i][1]));
	}
//	if (flg_B)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			p[i].sa = s[i][0], p[i].sb = s[i][1];
//			p[i].L = Find(s[i][0]); p[i].R = s[i][0].size() - p[i].L;
//			p[i].opt = 0;
//		}
//		for (int i = 1; i <= q; i++)
//		{
//			p[i + n].sa = t[i][0], p[i + n].sb = t[i][1];
//			p[i + n].L = Find(t[i][0]); p[i + n].R = t[i][0].size() - p[i + n].L;
//			p[i + n].opt = i;
//		}
//		sort(p + 1, p + n + q + 1);
//		for (int i = 1; i <= n + q; i++)
//		{
//			int dif = Find(p[i].sa) - Find(p[i].sb);
//			if (!p[i].opt)
//				vc[dif + MAXM].Update(p[i].R);
//			else
//			{
//				if (vc[dif + MAXM].empty())
//					c[p[i].opt] = 0;
//				else
//					c[p[i].opt] = upper_bound(vc[dif + MAXM].begin(), vc[dif + MAXM].end(), p[i].R) - vc[dif + MAXM].begin();
////				if (p[i].sa == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
////				{
////					for (int x : vc[dif + MAXM])
////						printf("%d\n", x);
////					cout << p[i].R << "\n" << dif << "\n";
////				}
//			}
//		}
//		for (int i = 1; i <= q; i++)
//		{
//			if (c[i] == 1)
//				cout << t[i][0] << "\n" << t[i][1] << "\n";
//			printf("%d\n", c[i]);
//		}
//		return 0;
//	}
	for (int i = 1; i <= q; i++)
	{
		int lst = -1, fst = -1;
		for (unsigned j = 0; j < t[i][0].size(); j++)
		{
			if (t[i][0][j] != t[i][1][j])
			{
				if (fst == -1)
					fst = j;
				lst = j;
			}
		}
//		printf("!! %d %d\n", fst, lst);
//		printf("?? %d\n", flg);
		int bs = BASE;
		a[0] = t[i][0][0] - 'a';
		for (unsigned j = 1; j < t[i][0].size(); j++)
			a[j] = (a[j - 1] + 1ll * bs * (t[i][0][j] - 'a') % MOD) % MOD, bs = 1ll * bs * BASE % MOD;
		bs = BASE;
		b[0] = t[i][1][0] - 'a';
		for (unsigned j = 1; j < t[i][0].size(); j++)
			b[j] = (b[j - 1] + 1ll * bs * (t[i][1][j] - 'a') % MOD) % MOD, bs = 1ll * bs * BASE % MOD;
		int ans = 0;
		for (int j = 0; j <= fst; j++)
		{
			for (unsigned k = lst; k < t[i][0].size(); k++)
			{
				int val = 1ll * Inv(Qpow(BASE, j)) * ((a[k] - (!j ? 0 : a[j - 1]) + MOD) % MOD) % MOD;
				val = (val + 1ll * C * (1ll << 30) * ((1ll * Inv(Qpow(BASE, j)) % MOD * ((b[k] - (!j ? 0 : b[j - 1]) + MOD) % MOD) % MOD) ^ 1738) % MOD) % MOD;
//					printf("val = %d\n", val);
				ans += c[val];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
