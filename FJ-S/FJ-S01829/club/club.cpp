#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

namespace preFile
{
	void init()
	{
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

typedef std::pair<int, int> pii;
const int maxn = 1e5 + 3;
struct node { int a1, a2, a3; }a[maxn];
int n, ans, cnt[4];
pii getmx(node);
pii getmd(node);
pii getmn(node);

bool cmp(node x, node y)
{
	int tx1 = getmx(x).first, tx2 = getmd(x).first, tx3 = getmn(x).first;
	int ty1 = getmx(y).first, ty2 = getmd(y).first, ty3 = getmn(y).first;
	if (tx1 - tx2 != ty1 - ty2)
		return tx1 - tx2 > ty1 - ty2;
	else
		return tx1 - tx3 > ty1 - ty3;
}

void solve()
{
	ans = 0; cnt[1] = cnt[2] = cnt[3] = 0;
	std::cin >> n; int up = n / 2;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
	std::sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		pii t1 = getmx(a[i]), t2 = getmd(a[i]), t3 = getmn(a[i]);
		if (cnt[t1.second] < up)
		{
			ans += t1.first;
			cnt[t1.second]++;
		}
		else if (cnt[t2.second] < up)
		{
			ans += t2.first;
			cnt[t2.second]++;
		}
		else
		{
			ans += t3.first;
			cnt[t3.second]++;
		}
	}
	std::cout << ans << '\n';
}

int main()
{
	preFile::init();
	int t; std::cin >> t;
	while (t--)
		solve();
	return 0;
}

pii getmx(node t)
{
	int mx = std::max({t.a1, t.a2, t.a3});
	if (t.a1 == mx)
		return {mx, 1};
	else if (t.a2 == mx)
		return {mx, 2};
	else
		return {mx, 3};
}

pii getmd(node t)
{
	pii tmp = getmx(t);
	if (tmp.second == 1)
	{
		if (t.a2 > t.a3)
			return {t.a2, 2};
		else
			return {t.a3, 3};
	}
	else if (tmp.second == 2)
	{
		if (t.a1 > t.a3)
			return {t.a1, 1};
		else
			return {t.a3, 3};
	}
	else
	{
		if (t.a1 > t.a2)
			return {t.a1, 1};
		else
			return {t.a2, 2};
	}
}

pii getmn(node t)
{
	int id1 = getmx(t).second, id2 = getmd(t).second;
	if (id1 > id2)
		std::swap(id1, id2);
	if (id1 == 1 && id2 == 2)
		return {t.a3, 3};
	else if (id1 == 1 && id2 == 3)
		return {t.a2, 2};
	else
		return {t.a1, 1};
}