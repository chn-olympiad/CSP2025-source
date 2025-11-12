#include <bits/stdc++.h>
#define int long long
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 2e5 + 50, P = 998244353;
int n, q, a[N], b[N], c[N], hs[N];
int p26[N], q26[N];
string s[N][2], t1, t2;

int qpow(int a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) (res *= a) %= P;
		(a *= a) %= P, k >>= 1;
	} return res;
}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	r(n) cin >> s[i][0] >> s[i][1];
	p26[0] = 1; r(N - 10) p26[i] = p26[i - 1] * 26 % P;
	rep(i, 0, N - 10) q26[i] = qpow(p26[i], P - 2);
	r(n)
	{
		int bs = 1, p = 0, q = 0;
		rep(j, 0, (int)s[i][0].size() - 1)
		{
			p = (p + bs * (s[i][0][j] - 'a' + 1)) % P;
			(bs *= 26) %= P;
		} bs = 1;
		rep(j, 0, (int)s[i][1].size() - 1)
		{
			q = (q + bs * (s[i][1][j] - 'a' + 1)) % P;
			(bs *= 26) %= P;
		}
		a[i] = p, b[i] = q, c[i] = s[i][0].size();
	}
	r(q)
	{
		int bs = 1, p = 0;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << "0\n";
			continue;
		}
		rep(j, 0, (int)t1.size() - 1)
		{
			hs[j] = (hs[j - 1] + bs * (t1[j] - 'a' + 1)) % P;
			(bs *= 26) %= P;
		} bs = 1;
		rep(j, 0, (int)t2.size() - 1)
		{
			p = (p + bs * (t2[j] - 'a' + 1)) % P;
			(bs *= 26) %= P;
		}
		int cnt = 0;
		rep(j, 0, (int)t1.size() - 1)
		{
			rep(k, 1, n)
			{
				//[j, j + c_i - 1]
				int l = j, r = j + c[k] - 1;
				int val = (hs[r] - (l == 0 ? 0 : hs[l - 1])) * q26[l] % P;
				if (val == a[k]) 
				{
					int aft = hs[t1.size() - 1] - val * p26[l] + b[k] * p26[l];
					if (aft == p) cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
