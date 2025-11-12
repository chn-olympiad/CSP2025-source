
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n, res;
struct stu {
	int a, b, c, mx, md;
} a[N];
vector<stu> ss[4];

int maxi(int a, int b, int c)
{
	if (a >= b && a >= c) return 1;
	if (b >= a && b >= c) return 2;
	else return 3;
}

int midi(int a, int b, int c)
{
	int mx = maxi(a, b, c);
	if (mx == 1) return b >= c ? 2 : 3;
	if (mx == 2) return a >= c ? 1 : 3;
	else return a >= b ? 1 : 2;
}

int maxv(int a, int b, int c)
{
	return max(a, max(b, c));
}

int midv(int a, int b, int c)
{
	int mx = maxv(a, b, c);
	if (mx == a) return max(b, c);
	if (mx == b) return max(a, c);
	else return max(a, b);
}

bool cmp(stu s1, stu s2)
{
	return s1.mx - s1.md < s2.mx - s2.md;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		scanf("%d", &n);
		res = 0;
		ss[1].clear(), ss[2].clear(), ss[3].clear();
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			a[i].mx = maxv(a[i].a, a[i].b, a[i].c);
			a[i].md = midv(a[i].a, a[i].b, a[i].c);
			ss[maxi(a[i].a, a[i].b, a[i].c)].push_back(a[i]);
			res += a[i].mx;
		}
		if (maxv(ss[1].size(), ss[2].size(), ss[3].size()) > (n >> 1))
		{
			int mx = maxi(ss[1].size(), ss[2].size(), ss[3].size()), sz = ss[mx].size();
			sort(ss[mx].begin(), ss[mx].end(), cmp);
			for (int i = 0; sz > (n >> 1); ++i, --sz)
				res -= ss[mx][i].mx - ss[mx][i].md;
		}
		cout << res << endl;
	}
	return 0;
}

