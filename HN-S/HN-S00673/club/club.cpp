#include <bits/stdc++.h>
using namespace std;
struct node
{
	int v, per, id, d;
};
const int N = 1e5 + 10;
int t, n, pail[10], p = 0;
bool vis_per[N];
int a[N][5];
node nub[N * 3];
void init ()
{
	for (int i = 1; i <= 3; i++)
		pail[i] = 0;
	for (int i = 1; i <= n; i++)
		vis_per[i] = 0;
	p = 0;
	return ;
}
bool cmp(int x, int y)
{
	return x > y;
}
bool cmp2(node x, node y)
{
	return x.d > y.d;
}
int main()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		init();
		int Max = n / 2;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int w[5] = {};
			int d[5] = {};
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j], w[j] = a[i][j];
			sort(w + 1, w + 1 + 3, cmp);
			for (int j = 1; j <= 3; j++)
			{
				if (w[1] == a[i][j]) d[j] = w[1] - w[2];
				else if (w[2] == a[i][j]) d[j] = w[2] - w[1];
				else d[j] = w[3] - w[1];
			}
			nub[++p] = {a[i][1], i, 1, d[1]};
			nub[++p] = {a[i][2], i, 2, d[2]};
			nub[++p] = {a[i][3], i, 3, d[3]};
		}
		sort(nub + 1, nub + 1 + p, cmp2);
		for (int i = 1; i <= p; i++)
		{
			int v = nub[i].v;
			int per = nub[i].per;
			int id = nub[i].id;
			if (vis_per[per] || pail[id] + 1 > Max) continue;
			pail[id]++;
			vis_per[per] = 1;
			ans += 1ll * v;
		}
		cout << ans << "\n";
	}
	return 0;
}

