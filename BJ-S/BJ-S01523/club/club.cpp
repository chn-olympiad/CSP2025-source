#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 10;

int T;
int n, ans;
struct node {
	int v, id;
} a[maxn][3];
int cnt[3];
int st[maxn], top; 
void init() {
	ans = 0;
	top = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
}
void solve() {
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
		cin >> a[i][0].v >> a[i][1].v >> a[i][2].v,
		a[i][0].id = 0, a[i][1].id = 1, a[i][2].id = 2,
		sort(a[i], a[i] + 3, [](const node& x, const node& y) {
			return x.v > y.v;
		}), 
		ans += a[i][0].v, cnt[a[i][0].id]++;
	if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) { cout << ans << "\n"; return; }
	int pos = (cnt[0] > n / 2 ? 0 : (cnt[1] > n / 2 ? 1 : 2));
	int tmp = cnt[pos] - n / 2;
	for (int i = 1; i <= n; i++)
		if (a[i][0].id == pos) 
			st[++top] = min(a[i][0].v - a[i][1].v, a[i][0].v - a[i][2].v);
	sort(st + 1, st + top + 1);
	for (int i = 1; i <= tmp; i++) ans -= st[i];
	cout << ans << "\n";
	return;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> T;	
	while (T--) solve();
	return 0;
}