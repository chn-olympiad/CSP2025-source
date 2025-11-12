#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

namespace IO
{
	char ch;
	inline void read() {}
	template<class T1, class... T2>
	inline void read(T1& num1, T2&... num2)
	{
		num1 = 0; ch = getchar();
		for (; !isdigit(ch); ch = getchar());
		for (; isdigit(ch); ch = getchar())
			num1 = num1 * 10 + (ch ^ '0');
		read(num2...);
	}
}
using IO::read;

const ll sha = 131;
const ll mod = 1e9 + 7;

const int N = 2e5 + 5;
const int Q = 2e5 + 5;
const int S = 5e6 + 5;

int n, q, len, slen;

char s1[N], s2[N];
ll sha1[N], sha2[N];

char t1[Q], t2[Q];

ll pw[S], arr[S];

ll cut(ll* arr, int l, int r)
{
	return (arr[r] - arr[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

ll calcsha(char* str, int n)
{
	ll res = 0;
	for (int i = 1; i <= n; ++i)
	{
		res = (res * sha + str[i]) % mod;
	}
	return res;
}

void calcarr(char* str, int n, ll* arr)
{
	for (int i = 1; i <= n; ++i)
	{
		arr[i] = (arr[i - 1] * sha + str[i]) % mod;
	}
}

int lth[S], rev[S], tot, ans, l, r;
map<pair<ll, ll>, int> htab[4000];

ll arr1[S], arr2[S];

ll ksm(ll a, ll k = mod - 2)
{
	ll res = 1;
	while (k)
	{
		if (k & 1) res = res * a % mod;
		a = a * a % mod; k >>= 1;
	}
	return res;
}

int main()
{
	freopen("replace1.in", "r", stdin);
	//freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	
	pw[0] = 1;
	for (int i = 1; i < S; ++i)
	{
		pw[i] = pw[i - 1] * sha % mod;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s%s", s1 + 1, s2 + 1);
		len = strlen(s1 + 1);
		sha1[i] = calcsha(s1 + 1, len);
		sha2[i] = calcsha(s2 + 1, len);
		if (!lth[len])
		{
			lth[len] = ++tot;
			rev[tot] = len;
		}
		++htab[lth[len]][{sha1[i], sha2[i]}];
	}
	
	while (q--)
	{
		scanf("%s%s", t1 + 1, t2 + 1);
		len = strlen(t1 + 1);
		if (len != strlen(t2 + 1))
		{
			printf("0\n");
			continue;
		}
		ans = 0;
		l = 1e9, r = 0;
		for (int i = 1; i <= len; ++i)
		{
			if (t1[i] != t2[i])
			{
				l = min(l, i);
				r = max(r, i);
			}
		}
		calcarr(t1 + 1, len, arr1);
		calcarr(t2 + 1, len, arr2);
		if (l > r)
		{
			for (int i = 1; i <= tot; ++i)
			{
				slen = rev[i] - 1;
				for (int j = 1; j + slen <= len; ++j)
				{
					ans += htab[i][{cut(arr1, j, j + slen) * ksm(pw[j - 1]) % mod, cut(arr2, j, j + slen) * ksm(pw[j - 1]) % mod}];
				}
			}
		}
		else
		{
			for (int i = 1; i <= tot; ++i)
			{
				slen = rev[i] - 1;
				for (int j = max(r - slen, 1); j <= l && j + slen <= len; ++j)
				{
					ans += htab[i][{cut(arr1, j, j + slen) * ksm(pw[j - 1]) % mod, cut(arr2, j, j + slen) * ksm(pw[j - 1]) % mod}];
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
