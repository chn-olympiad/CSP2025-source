#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5,MAXN = 5e6 + 5,p = 322771,mod = 998244353;
int _h[MAXN],base[MAXN];
struct node
{
	int hfrom,hto,len;
}ss[Maxn];
inline int geth(string S)
{
	int ansh = 0;
	for (int i = 0; i < S.size(); i++)
	{
		ansh = 1ll * ansh * p % mod;
		(ansh += S[i]) %= mod;
	}
	return ansh;
}
inline int gethash(int l,int r)
{
	return (_h[r] - 1ll * _h[l - 1] * base[r - l + 1] % mod + mod) % mod;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,H2,H1,ans,L;
	string tmp1,tmp2,t1,t2;
	cin >> n >> q;
	base[0] = 1;
	for (int i = 1; i <= 5000000; i++) base[i] = 1ll * base[i - 1] * p % mod;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp1 >> tmp2;
		ss[i] = (node){geth(tmp1),geth(tmp2),(int)tmp1.size()};
	}
	if (n <= 100)
	{
		while (q--)
		{
			ans = 0;
			cin >> t1 >> t2;
			H2 = geth(t2),L = t1.size();
			for (int i = 1; i <= L; i++) _h[i] = (1ll * _h[i - 1] * p % mod + t1[i - 1]) % mod;
			H1 = _h[t1.size()];
			for (int i = 1; i <= L; i++)
			{
				for (int j = 1,r; j <= n; j++)
				{
					r = i + ss[j].len - 1;
					if (r > L) continue;
					if (gethash(i,r) == ss[j].hfrom && (H1 + 1ll * ((ss[j].hto - ss[j].hfrom + mod) % mod) * base[L - r] % mod) % mod == H2) ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	else
	{
		while (q--)
		{
			cout << "0\n";
		}
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

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
