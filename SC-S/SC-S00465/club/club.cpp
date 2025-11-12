#include <cstdio>
#include <vector>
#include <algorithm>
inline void read(int &x)
{
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c & 15);
}
const int MAXN = 1e5 + 7;
struct Stu { std::pair<int, int> a[3]; int p; } a[MAXN];
std::vector<Stu> vec[3];
int T, n, ans = 0;
inline void solve()
{
	read(n), vec[0].clear(), vec[1].clear(), vec[2].clear(), ans = 0;
	for (int i = 1; i <= n; ++i)
		read(a[i].a[0].first), read(a[i].a[1].first), read(a[i].a[2].first),
		a[i].a[0].second = 0, a[i].a[1].second = 1, a[i].a[2].second = 2;
	for (int i = 1; i <= n; ++i)
		std::sort(a[i].a, a[i].a + 3, [&](const std::pair<int, int> &x, const std::pair<int, int> &y) { return x.first > y.first; }),
		vec[a[i].a[a[i].p = 0].second].push_back(a[i]), ans += a[i].a[0].first;
	for (int tim = 0; tim < 3; ++tim)
	{
		std::sort(vec[0].begin(), vec[0].end(), [&](const Stu &x, const Stu &y) { return x.p == 2 || x.a[x.p].first - x.a[x.p + 1].first > y.a[y.p].first - y.a[y.p + 1].first; }),
		std::sort(vec[1].begin(), vec[1].end(), [&](const Stu &x, const Stu &y) { return x.p == 2 || x.a[x.p].first - x.a[x.p + 1].first > y.a[y.p].first - y.a[y.p + 1].first; }),
		std::sort(vec[2].begin(), vec[2].end(), [&](const Stu &x, const Stu &y) { return x.p == 2 || x.a[x.p].first - x.a[x.p + 1].first > y.a[y.p].first - y.a[y.p + 1].first; });
		for (int i = 0; i < 3; ++i)
			while ((int)(vec[i].size()) > (n >> 1))
				a[0] = vec[i].back(), ++a[0].p, vec[i].pop_back(), vec[a[0].a[a[0].p].second].push_back(a[0]), ans += a[0].a[a[0].p].first - a[0].a[a[0].p - 1].first;
//				printf("%d %d %d %d\n", a[0].a[0].second, a[0].a[1].second, a[0].a[2].second, a[0].p), fflush(stdout);
	}
	printf("%d\n", ans);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (read(T); T; --T)
		solve();
	fclose(stdin), fclose(stdout);
	return 0;
}