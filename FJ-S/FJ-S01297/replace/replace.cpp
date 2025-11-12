#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 5e6 + 10;
const ULL P = 13131;

char s1[N], s2[N];
ULL p[N], h1[N], h2[N];
ULL hl[N], hd1[N], hd2[N], hr[N];
int L[N], R[N];

void init(int n)
{
	p[0] = 1;
	for (int i = 1; i <= n; i ++ ) p[i] = p[i - 1] * P;
}

ULL get(ULL h[], int l, int r)
{
	if (l > r) return 0;
	return h[r] - h[l - 1] * p[r - l + 1];
}

void work(int id)
{
	int len = strlen(s1 + 1);
	int l = 0, r = 0;
	for (int i = 1; i <= len; i ++ )
	{
		h1[i] = h1[i - 1] * P + s1[i], h2[i] = h2[i - 1] * P + s2[i];
		if (s1[i] != s2[i])
		{
			if (!l) l = i;
			r = i;
		}
	}
	hl[id] = get(h1, 1, l - 1), hr[id] = get(h1, r + 1, len);
	hd1[id] = get(h1, l, r), hd2[id] = get(h2, l, r);
	L[id] = l - 1, R[id] = len - r;
}

void solve()
{
	init(5e6);
	int n, Q; scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%s%s", s1 + 1, s2 + 1);
		work(i);
	}
	while (Q -- )
	{
		scanf("%s%s", s1 + 1, s2 + 1);
		work(n + 1); int len = strlen(s1 + 1), res = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if (hd1[i] == hd1[n + 1] && hd2[i] == hd2[n + 1] && L[n + 1] >= L[i] && R[n + 1] >= R[i] && 
			    hl[i] == get(h1, L[n + 1] - L[i] + 1, L[n + 1]) && hr[i] == get(h1, len - R[n + 1] + 1, len - R[n + 1] + R[i]))
				res ++ ;
		}
		printf("%d\n", res);
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T = 1;
	while (T -- ) solve();
	return 0;
}
