#include <iostream>
#include <algorithm>
const int maxn = 1e5 + 10;
using namespace std;
int n, t, ans, sum, k, judge;
struct node{
	int a, b, c, id;
}x[maxn];
bool cmp(node m, node n) {
	return m.id < n.id;
}
void dfs(int d) {
	if (d > n) {
		ans = max(ans, sum);
		return;
	}
	if (x[0].a < k) {
		sum += x[d].a, x[0].a++;
		dfs(d + 1);
		sum -= x[d].a, x[0].a--;
	} 
	if (x[0].b < k) {
		sum += x[d].b, x[0].b++;
		dfs(d + 1);
		sum -= x[d].b, x[0].b--;
	} 
	if (x[0].c < k) {
		sum += x[d].c, x[0].c++;
		dfs(d + 1);
		sum -= x[d].c, x[0].c--;
	} 
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0, sum = 0, k = n / 2, judge = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i].a >> x[i].b >> x[i].c;
			x[i].id = x[i].a - x[i].b;judge += x[i].c;
		}
		if (n <= 30) {
			x[0].a = x[0].b = x[0].c = 0;
			dfs(1);
		} else {
			sort(x + 1, x + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) 
				ans += x[i].b;
			for (int i = n / 2 + 1; i <= n; i++) 
				ans += x[i].a;
		}
		cout << ans << '\n';
	}
	return 0;
}
