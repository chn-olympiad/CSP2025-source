#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 1;
string x, y, s1[N], s2[N];
int n, q, B[N], BF1[N], BF2[N];
bool FF = 1, FFC = 1;
bool check(string x, string y)
{
	if(FF == 0)
	{
		return 0;
	}
	
	int cnt = 0;
	int xz = x.size(), yz = y.size();
	for(int i = 0; i < xz; i++)
	{
		if(x[i] == 'b')
		{
			cnt++;
		}
		else if(x[i] != 'a')
		{
			FF = 0;
			break;
		}
	}
	if(cnt != 1)
	{
		FF = 0;
	}
	cnt = 0;
	if(FF)
	{
		for(int i = 0; i < yz; i++)
		{
			if(y[i] == 'b')
			{
				cnt++;
			}
			else if(y[i] != 'a')
			{
				FF = 0;
				break;
			}
		}
	}
	if(cnt != 1)
	{
		FF = 0;
	}
	return FF;
}
void solve()
{
	if(FFC)
	{
		for(int i = 1; i <= n; i++)
		{
			int XX = s1[i].find('b'), YY = s2[i].find('b');
			B[i] = XX - YY;
			BF1[i] = XX, BF2[i] = YY;
		}
		FFC = 0;
	}
	int ans = 0, B1 = x.find('b'), B2 = y.find('b');
	for(int i = 1; i <= n; i++)
	{
		if(B[i] == (B1 - B2))
		{
			if(B1 < BF1[i])
			{
				continue;
			}
			if(B2 < BF2[i])
			{
				continue;
			}
			int rr1 = s1[i].size() - BF1[i], rr2 = s2[i].size() - BF2[i];
			int RR1 = x.size() - B1, RR2 = y.size() - B2;
			if(RR1 < rr1)
			{
				continue;
			}
			if(RR2 < rr2)
			{
				continue;
			}
			ans++;
		}
	}
	cout << ans << "\n";
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
		if(FF == 1)
		if(!check(s1[i], s2[i]))FF = 0;
	}
	while(q--)
	{
		int ans = 0;
		cin >> x >> y;
		if(x.size() != y.size())
		{
			cout << "0\n";
			continue;
		}
		if(check(x, y))
		{
			solve();
			continue;
		}
		int sz = x.size();
		for(int i = 1; i <= n; i++)
		{
			int szz = s1[i].size();
			string X = x;
			for(int j = 0; j <= sz - szz; j++)
			{
				bool f = 1;
				for(int k = j; k < j + szz; k++)
				{
					if(x[k] != s1[i][k - j])
					{
						f = 0;
						break;
					}
				}
				if(f)
				{
					for(int k = j; k < j + szz; k++)
					{
						x[k] = s2[i][k - j];
					}
					if(x == y)
					{
						ans++;
					}
					x = X;
				}
			}
		}
		cout << ans << "\n";
	}
}
