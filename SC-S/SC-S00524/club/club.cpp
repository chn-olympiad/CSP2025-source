#include <bits/stdc++.h>
using namespace std;
template<typename _Tp>
void read(_Tp &res) {
	res = 0;
	bool f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		f |= (ch == '-'), ch = getchar();
	while (ch >= '0' && ch <= '9')
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	res = f ? -res : res;
}
constexpr int MAXN = 1e5 + 5;
int T, n;
int a[MAXN][5];
bool flag1 = 1, flag2 = 1;
int dfs(int cnt1, int cnt2,int cnt3, int res, int pos) {
	if (pos > n)
		return res;
	int ans = 0;
	if (cnt1 < n / 2)
		ans = max(dfs(cnt1 + 1, cnt2, cnt3, res + a[pos][1], pos + 1), ans);
	if (cnt2 < n / 2)
		ans = max(dfs(cnt1, cnt2  + 1, cnt3, res + a[pos][2], pos + 1), ans);
	if (cnt3 < n / 2)
		ans = max(dfs(cnt1, cnt2, cnt3  + 1, res + a[pos][3], pos + 1), ans);
	return ans;
}
bool cmp(int a[5], int b[5]) {
	return a[1] > b[1];
}
void solve1() {
	priority_queue<int> que;
	for (int i = 1; i <= n; ++i)
		que.push(a[i][1]);
	long long res = 0;
	for (int i = 1; i <= n / 2; ++i)
		res += que.top(), que.pop();
	cout << res << '\n';
}
void solve2() {
	priority_queue<int> que;
	for (int i = 1; i <= n; ++i)
		que.push(max(a[i][1], a[i][2]));
	long long res = 0;
	for (int i = 1; i <= n / 2; ++i)
		res += que.top(), que.pop();
	cout << res << '\n';
}
void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(a[i][1]), read(a[i][2]), read(a[i][3]);
		if (!a[i][2] || !a[i][3])
			flag1 = 0;
		if (!a[i][3])
			flag2 = 0;
	}
	if (n <= 10)
		return cout << dfs(0, 0, 0, 0, 1) << '\n',void();
	if (flag1)
		return solve1(), void();
	if (flag2)
		return solve2(), void();
	int p1, p2;
	int ans = 0;
	int begin_t = clock();
	for (int i = 1; clock() - begin_t <= 0.15 * CLOCKS_PER_SEC; ++i) {
		random_shuffle(a + 1, a + n + 1);
		for (int k = 1; k <= 10; ++k) {
			int sum1 = 0, sum2 = 0, sum3 = 0;
			do {
				p1 = rand() % (n >> 1) + 1, p2 = rand() % (n >> 1) + p1 + 1;
			} while (p2 < (n >> 1));
			for (int j = 1; j <= p1; ++j)
				sum1 += a[j][1];
			for (int j = p1 + 1; j <= p2; ++j)
				sum2 += a[j][2];
			for (int j = p2 + 1; j <= n; ++j)
				sum3 += a[i][3];
			ans = max(ans, sum1 + sum2 + sum3);
		}
	}
	cout << ans << '\n';
}
int main() {
#if DEBUG
	freopen(".\\club\\club2.in", "r", stdin);
	freopen(".\\club\\club2.out", "w", stdout);
#else
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif
	srand(time(0));
	read(T);
	while (T--)
		solve();
	return 0;
}