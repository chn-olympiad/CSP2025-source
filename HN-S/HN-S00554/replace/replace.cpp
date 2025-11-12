#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, base = 131, p = 1e9 + 7;
long long n, m, l[N], hs[N][3], hsq[3][N], lq, pw[N], num, w[N][3], wq[3];
string s, t[3];
bool B = 1;
long long qry(int g, int l, int r)
{
	return (hsq[g][r] - hsq[g][l - 1] * pw[r - l + 1] % p + p) % p;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	pw[0] = 1;
	for (int i = 1;i <= 2000;i++)
	{
		pw[i] = pw[i - 1] * base % p;
	}
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= 2;j++)
		{
			cin >> s;
			l[i] = s.length();
			s = " " + s;
			for (int k = 1;k <= l[i];k++)
			{
				hs[i][j] = (hs[i][j] * base + s[k]) % p;
				if (s[k] > 'b')
				{
					B = 0;
				}
				if (s[k] == 'b')
				{
					if (w[i][j])
					{
						B = 0;
					}
					w[i][j] = k;
				}
			}
		}
	}
	for (int q = 1;q <= m;q++)
	{
		cin >> t[1] >> t[2];
		lq = t[1].length();
		t[1] = " " + t[1], t[2] = " " + t[2];
		for (int i = 1;i <= 2;i++)
		{
			for (int j = 1;j <= lq;j++)
			{
				hsq[i][j] = (hsq[i][j - 1] * base + t[i][j]) % p;
				if (t[i][j] == 'b')
				{
					if (wq[i])
					{
						B = 0;
					}
					wq[i] = j;
				}
			}
		}
		if (B && q == 1)
		{
			for (int i = 1;i <= n;i++)
			{
				if (w[i][1] - w[i][2] == wq[1] - wq[2] && wq[1] >= w[i][1] && lq - wq[2] >= l[i] - w[i][2])
				{
					num++;
				}
			}
			cout << num << "\n";
			return 0;
		}
		num = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j + l[i] - 1 <= lq;j++)
			{
				if (qry(1, 1, j - 1) == qry(2, 1, j - 1) && qry(1, j + l[i], lq) == qry(2, j + l[i], lq) && qry(1, j, j + l[i] - 1) == hs[i][1] && qry(2, j, j + l[i] - 1) == hs[i][2])
				{
					num++;
					break;
				}
			}
		}
		cout << num << "\n";
	}
	return 0;
}
/*
4 1
aba aba
ab ba
aab aba
abaa baaa

aba baa

*/
