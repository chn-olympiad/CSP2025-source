#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;
int n, k, ai, s[N];
ll ans;
pair<int, int> p[(ll)2e7];

inline int rd()
{
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

int sum(int l, int r)
{
	return s[l - 1] ^ s[r];
}

bool vis(int l, int r)
{
	for(int i = 1; i <= ans; i++)
	{
		if((p[i].first >= l && p[i].first <= r) || 
		   (p[i].second >= l && p[i].second <= r))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = rd(), k = rd();
	for(int i = 1; i <= n; i++)
	{
		ai = rd();
		s[i] = s[i - 1] ^ ai;
	}
//	for(int l = 1; l <= n; l++)
//	{
//		for(int r = l; r <= n; r++)
//		{
//			if(sum(l, r) == k)
//			printf("l = %d, r = %d, sum = %d\n", l, r, sum(l, r));
//		}
//	}
	for(int len = 1; len <= n; len++)
	{
		for(int l = 1; (l + len - 1) <= n; l++)
		{
			int r = l + len - 1;
			if(sum(l, r) == k && (!vis(l, r)))
			{
//				cout << l << ' ' << r << '\n';
				p[++ans].first = l, p[ans].second = r;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
