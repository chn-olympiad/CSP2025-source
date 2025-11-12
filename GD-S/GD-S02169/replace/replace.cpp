#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef unsigned int uint;
typedef pair <uint, uint> PUU;
const int N = 5e6 + 5;
int n, q;
string s[2], t[2];

void read(int &x)
{
	x = 0;char c = getchar();
	while(c < 48 || 57 < c)c = getchar();
	while(48 <= c && c <= 57)x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}

int pw1[N], pw2[N];
const int BS = 131, P1 = 998244353, P2 = 1e9 + 7;
void init(int n)
{
	pw1[0] = pw2[0] = 1;
	for(int i = 1;i <= n;i++)
		pw1[i] = 1ll * pw1[i - 1] * BS % P1, pw2[i] = 1ll * pw2[i - 1] * BS % P2;
}
struct hss
{
	int len, hs1[N], hs2[N];
	void init(string s)
	{
		len = s.length();
		for(int i = 1;i <= len;i++)
			hs1[i] = (1ll * hs1[i - 1] * BS % P1 + (s[i - 1] - 96)) % P1, hs2[i] = (1ll * hs2[i - 1] * BS % P2 + (s[i - 1] - 96)) % P2;
	}
	uint all(){return 1u * hs1[len] * hs2[len];}
	uint get(int l, int r){return 1u * ((hs1[r] - 1ll * hs1[l - 1] * pw1[r - l + 1] % P1 + P1) % P1) * ((hs2[r] - 1ll * hs2[l - 1] * pw2[r - l + 1] % P2 + P2) % P2);}
}hs1, hs2;
map <PUU, int> mp;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	read(n), read(q), init(5e6);
	for(int i = 1;i <= n;i++)
	{
		cin >> s[0] >> s[1];
		hs1.init(s[0]), hs2.init(s[1]);
		mp[make_pair(hs1.all(), hs2.all())]++;
	}
	while(q--)
	{
		int len, res = 0;
		cin >> t[0] >> t[1], len = t[0].length();
		if(t[0].length() != t[1].length()){puts("0");continue;}
		hs1.init(t[0]), hs2.init(t[1]);
		for(int i = 1;i <= len;i++)
			for(int j = 1;j <= len - i + 1;j++)
			{
				if(hs1.get(1, i - 1) != hs2.get(1, i - 1))continue;
				if(i + j <= len && hs1.get(i + j, len) != hs2.get(i + j, len))continue;
				if(mp.count(make_pair(hs1.get(i, i + j - 1), hs2.get(i, i + j - 1))))
					res += mp[make_pair(hs1.get(i, i + j - 1), hs2.get(i, i + j - 1))];
			}
		printf("%d\n", res);
	}
	return 0;
}
