#include<bits/stdc++.h>
using namespace std;
#define int long long
const int base = 998244353, mod = 1e9 + 9;
vector<int> h1[200005], h2[200005], h3, h4, H1[200005], H2[200005];
int Pow[5000005];
int pos[200005], siz[200005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	Pow[0] = 1;
	for(int i = 1; i <= 5000000; i ++)
	{
		Pow[i] = Pow[i - 1] * base % mod;
	}
	for(int i = 1; i <= n; i ++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		h1[i].resize(s1.size() + 5), h2[i].resize(s2.size() + 5);
		H1[i].resize(s1.size() + 5), H2[i].resize(s2.size() + 5);
		pos[i] = -1;
		for(int j = 0; j < s1.size(); j ++)
		{
			if(s1[j] != s2[j])
			{
				pos[i] = j + 1;
				siz[i] = s1.size() - j;
				for(int k = 1; k <= j + 1; k ++)
				{
					H1[i][k] = (H1[i][k - 1] * base + (s1[k - 1] - 'a' + 1)) % mod;
					H2[i][k] = (H2[i][k - 1] * base + (s2[k - 1] - 'a' + 1)) % mod;
				}
				for(int k = 1; j + k <= s1.size(); k ++)
				{
					h1[i][k] = (h1[i][k - 1] * base + (s1[j + k - 1] - 'a' + 1)) % mod;
					h2[i][k] = (h2[i][k - 1] * base + (s2[j + k - 1] - 'a' + 1)) % mod;
				}
				//cout << pos[i] << ' ' << siz[i] << endl;
				break;
			}
		}
	}
	for(int i = 1; i <= q; i ++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		h3.resize(s1.size() + 5), h4.resize(s2.size() + 5);
		for(int j = 0; j < s1.size(); j ++)
		{
			h3[j + 1] = (h3[j] * base + (s1[j] - 'a' + 1)) % mod;
			h4[j + 1] = (h4[j] * base + (s2[j] - 'a' + 1)) % mod;
		}
		int ans = 0;
		for(int j = 0; j < s1.size(); j ++)
		{
			if(s1[j] != s2[j])
			{
				for(int k = 1; k <= n; k ++)
				{
					if(pos[k] == -1 || j + siz[k] > s1.size() || j < pos[k] - 1) continue;
					//cout << (h3[j + siz[k]] - h3[j] * Pow[siz[k]]) << ' ' << h1[k][siz[k]] << endl;
					if((h3[j + siz[k]] + mod - h3[j] * Pow[siz[k]] % mod) % mod == h1[k][siz[k]] &&
						(h3[j] + mod - h3[j - pos[k] + 1] * Pow[pos[k] - 1] % mod) % mod == H1[k][pos[k] - 1])
					{
						//cout << h3[s1.size()] - h3[j + siz[k]] * Pow[s1.size() - j - siz[k]] + h3[j] * Pow[s1.size() - j] + h2[k][siz[k]] * Pow[s1.size() - j - siz[k]] << ' ' << h4[s2.size()] << endl;
						if((h3[s1.size()] + mod - h3[j + siz[k]] * Pow[s1.size() - j - siz[k]] % mod + h3[j] * Pow[s1.size() - j]
							+ h2[k][siz[k]] * Pow[s1.size() - j - siz[k]] % mod) % mod == h4[s2.size()])
						{
							ans ++;
						}
					}
				}
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
