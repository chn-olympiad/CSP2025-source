#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
struct node
{
	int a[4], b[4], c[4];
} s[N];

bool cmp (node x, node y)
{
	if (x.a[x.c[1]] == y.a[y.c[1]])
	{
		if (x.a[x.c[2]] == y.a[y.c[2]]) return x.a[x.c[3]] > y.a[y.c[3]];
		return x.a[x.c[2]] > y.a[y.c[2]];
	}
	else return x.a[x.c[1]] > y.a[y.c[1]];
}

int main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int t;
	scanf ("%d", &t);
	while (t --)
	{
		memset (s, 0, sizeof (s));
		int n, ax = 0, bx = 0, cx = 0;
		long long ans = 0;
		scanf ("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			scanf ("%d%d%d", &s[i].a[1], &s[i].a[2], &s[i].a[3]);
			if (s[i].a[1] >= s[i].a[2] && s[i].a[1] >= s[i].a[3])
			{
				s[i].c[1] = 1;
				if (s[i].a[2] >= s[i].a[3]) s[i].c[2] = 2, s[i].c[3] = 3;
				else s[i].c[2] = 3, s[i].c[3] = 2;
			}
			else if (s[i].a[2] >= s[i].a[1] && s[i].a[2] >= s[i].a[3])
			{
				s[i].c[1] = 2;
				if (s[i].a[1] >= s[i].a[3]) s[i].c[2] = 1, s[i].c[3] = 3;
				else s[i].c[2] = 3, s[i].c[3] = 1;
			}
			else
			{
				s[i].c[1] = 3;
				if (s[i].a[1] >= s[i].a[2]) s[i].c[2] = 1, s[i].c[3] = 2;
				else s[i].c[2] = 2, s[i].c[3] = 1;
			}
		}
		sort (s + 1, s + n + 1, cmp);
//		for (int i = 1; i <= n; i ++) cout << s[i].a[1] << " " << s[i].a[2] << " " << s[i].a[3] << "   " << s[i].b[1] << " " << s[i].b[2] << " " << s[i].b[3] << "   " << s[i].c[1] << " " << s[i].c[2] << " " << s[i].c[3] << "\n";
		for (int i = 1; i <= n; i ++)
		{
			if (s[i].c[1] == 1 && ax < n / 2) ax = ax + 1, ans = ans + s[i].a[1];
			else if (s[i].c[1] == 1 && s[i].c[2] == 2) bx = bx + 1, ans = ans + s[i].a[2]; 
			else if (s[i].c[1] == 1 && s[i].c[2] == 3) cx = cx + 1, ans = ans + s[i].a[3]; 
			if (s[i].c[1] == 2 && bx < n / 2) bx = bx + 1, ans = ans + s[i].a[2];
			else if (s[i].c[1] == 2 && s[i].c[2] == 1) ax = ax + 1, ans = ans + s[i].a[1]; 
			else if (s[i].c[1] == 2 && s[i].c[2] == 3) cx = cx + 1, ans = ans + s[i].a[3]; 
			if (s[i].c[1] == 3 && cx < n / 2) cx = cx + 1, ans = ans + s[i].a[3];
			else if (s[i].c[1] == 3 && s[i].c[2] == 1) ax = ax + 1, ans = ans + s[i].a[1]; 
			else if (s[i].c[1] == 3 && s[i].c[2] == 2) bx = bx + 1, ans = ans + s[i].a[2]; 
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
