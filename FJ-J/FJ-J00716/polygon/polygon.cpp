#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 5e3 + 10;
const int MOD = 998244353;
int n, ans, mx, a[N];
void dfs(int k, int s, int mx, int lst) {
	if (k > 3) {
		ans += (s > 2 * mx);
	}
	if (k > n) {
		return;
	}
	for (int i = lst + 1; i <= n; i++) {
		dfs(k + 1, s + a[i], max(mx, a[i]), i);
	}
}
int main() {
	//froepen("polygon.in", "r", stdin);
	//froepen("polygon.out", "w", stdout);
	//freeopen("polygon.in", "r", stdin);
	//freeopen("polygon.out", "w", stdout);
	//freopan("polygon.in", "r", stdin);
	//freopan("polygon.out", "w", stdout);
	//freopen("polygin.in", "r", stdin);
	//freopen("polygin.out", "w", stdout);
	//freopen("polygon.in", r, stdin);
	//freopen("polygon.out", w, stdout);
	//freopen("polygon.in", "r", "stdin");
	//freopen("polygon.out", "w", "stdout");
	//freopen(polygon.in, "r", stdin);
	//freopen(polygon.out, "w", stdout);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	Write by Na1L0n9
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if (n <= 20) {
		dfs(1, 0, 0, 0);
		cout << ans;
	}
	else {
		if (mx == 1) {
			int cur = 0;
			for (int i = 3; i <= n; i++) {
				cur = (cur * 2 + 1) % MOD;
				ans = (ans * 2 + cur) % MOD;
			}
			cout << ans;
		}
	}
	return 0;
}
// 1 0
// 2 0 *2+0
// 3 1 *2+1
// 4 5 *2+3
// 5 16 *2+6
// 6 42 *2+10
// 7 99 *2+15
// 我太强了，T4居然能打出60pts的做法，看来再过几年我就可以吊打tourist然后AKIOI了！ 
