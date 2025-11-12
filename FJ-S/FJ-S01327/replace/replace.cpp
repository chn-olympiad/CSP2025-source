#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef unsigned long long u64;

const int N = 5e5 + 8, M = 5e6 + 8, SGM = 26;
const u32 MOD[2] {1004535809, 998244353}, BS[2] {131, 101};

struct H
{
	u32 a[2];
};

H operator+(const H& x, const H& y)
{
	H res;
	for(int i = 0; i < 2; i++)
	{
		res.a[i] = x.a[i] + y.a[i];
		if(res.a[i] >= MOD[i])
			res.a[i] -= MOD[i];
	}
	return res;
}

H operator<<(const H& x, int y)
{
#ifdef DEBUG
	assert(y == 1);
#endif
	H res;
	for(int i = 0; i < 2; i++)
		res.a[i] = (u32)(1ull * x.a[i] * BS[i] % MOD[i]);
	return res;
}

bool operator==(const H& x, const H& y)
{ return x.a[0] == y.a[0] && x.a[1] == y.a[1]; }

struct custom_hash
{
	u64 operator()(H h) const
	{
		u64 x = ((u64)h.a[1] << 32) | h.a[0];
		return x ^ (x >> 31);
	}
};

H ctoh(char c)
{ return H{(u32)c, (u32)c}; } 

H calcsubh(const char* s, int l, int r, bool rev)
{
	H h {0, 0};
	if(!rev)
	{
		for(int i = l; i <= r; i++)
			h = (h << 1) + ctoh(s[i]);
	}
	else
	{
		for(int i = r; i >= l; i--)
			h = (h << 1) + ctoh(s[i]);
	}
	return h;
}

char s[M], t[M];

H calch(int len, int& l, int &r)
{
	l = 0, r = 0;
	for(int j = 1; j <= len; j++)
	{
		if(s[j] != t[j])
		{
			if(!l)
				l = j;
			r = j;
		}
	}
	if(!l)
		return {0, 0};
	H h;
	h.a[0] = h.a[1] = 0;
	for(int j = l; j <= r; j++)
	{
		h = (h << 1) + ctoh(s[j]);
		h = (h << 1) + ctoh(t[j]);
	}
	return h;
}

unordered_map<H, vector<int>, custom_hash> mp;
H strh[N][3];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		int len = (int)strlen(s + 1);
		int l, r;
		H h = calch(len, l, r);
		if(!l)
			continue;
		strh[i][0] = h;
		mp[h].push_back(i);
		strh[i][1] = calcsubh(s, 1, l - 1, true);
		strh[i][2] = calcsubh(s, r + 1, len, false);
	}
	while(q--)
	{
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		if(strlen(s + 1) != strlen(t + 1))
		{
			puts("0");
			continue;
		}
		int len = (int)strlen(s + 1), l, r;
		H h = calch(len, l, r);
		unordered_set<H, custom_hash> s1, s2;
		H hh {0, 0};
		s1.insert(hh);
		for(int i = l - 1; i >= 1; i--)
		{
			hh = (hh << 1) + ctoh(s[i]);
			s1.insert(hh);
		}
		hh = H{0, 0};
		s2.insert(hh);
		for(int i = r + 1; i <= len; i++)
		{
			hh = (hh << 1) + ctoh(s[i]);
			s2.insert(hh);
		}
		int ans = 0;
		for(int i : mp[h])
		{
			if(s1.count(strh[i][1]) && s2.count(strh[i][2]))
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}