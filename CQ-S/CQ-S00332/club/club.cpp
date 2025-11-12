#include <bits/stdc++.h>
#define IAKIOI ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pre(i, r, l) for (int i = r; i >= l; i--)
#define re read()
#define wr(n) write(n)
#define endl puts("")
#define sp putchar(' ')

const int N = 1e5 + 10, M = 5e4 + 10;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

inline int read() {
	int f = 1, y = 0;
	char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) y = (y << 1) + (y << 3) + (c ^ 48), c = getchar();
	return f * y;
}

inline void write(int n) {
	if (n < 0) n = -n, putchar('-');
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}

struct node {
	int a, b, c;
}a[N];

int n;

int calc1() {
	int ans = 0;
	priority_queue<pii, vector<pii>, greater<pii> > x, y, z;
	rep(i, 1, n) {
		if (x.size() >= n / 2) {
			pii X = x.top();
			int val = X.first, id = X.second;
			int sum1 = ans + a[i].b, sum2 = ans + a[i].c;
			if (ans - val + a[i].a + a[id].b > sum1 && ans - val + a[i].a + a[id].c > sum2) {
				int A = ans - val + a[i].a + a[id].b, B = ans - val + a[i].a + a[id].c;
				if (A > B) x.pop(), x.push({a[i].a, i}), y.push({a[id].b, id}), ans += a[id].b + a[i].a - val;
				else x.pop(), x.push({a[i].a, i}), y.push({a[id].c, id}), ans += a[id].c + a[i].a - val;
			}
			else if (ans - val + a[i].a + a[id].b > sum1) x.pop(), x.push({a[i].a, i}), y.push({a[id].b, id}), ans += a[id].b + a[i].a - val;
			else if (ans - val + a[i].a + a[id].c > sum2) x.pop(), x.push({a[i].a, i}), z.push({a[id].c, id}), ans += a[id].c + a[i].a - val;
			else if (sum1 > sum2) y.push({a[i].b, i}), ans += a[i].b;
			else z.push({a[i].c, i}), ans += a[i].c;
		}
		else x.push({a[i].a, i}), ans += a[i].a;
	}
	return ans;
}

int calc2() {
	int ans = 0;
	priority_queue<pii, vector<pii>, greater<pii> > x, y, z;
	rep(i, 1, n) {
		if (x.size() >= n / 2) {
			pii X = x.top();
			int val = X.first, id = X.second;
			int sum1 = ans + a[i].a, sum2 = ans + a[i].c;
			if (ans - val + a[i].b + a[id].a > sum1 && ans - val + a[i].b + a[id].c > sum2) {
				int A = ans - val + a[i].b + a[id].a, B = ans - val + a[i].b + a[id].c;
				if (A > B) x.pop(), x.push({a[i].b, i}), y.push({a[id].a, id}), ans += a[id].a + a[i].b - val;
				else x.pop(), x.push({a[i].b, i}), y.push({a[id].c, id}), ans += a[id].c + a[i].b - val;
			}
			else if (ans - val + a[i].b + a[id].a > sum1) x.pop(), x.push({a[i].b, i}), y.push({a[id].a, id}), ans += a[id].a + a[i].b - val;
			else if (ans - val + a[i].b + a[id].c > sum2) x.pop(), x.push({a[i].b, i}), z.push({a[id].c, id}), ans += a[id].c + a[i].b - val;
			else if (sum1 > sum2) y.push({a[i].a, i}), ans += a[i].a;
			else z.push({a[i].c, i}), ans += a[i].c;
		}
		else x.push({a[i].b, i}), ans += a[i].b;
	}
	return ans;
}

int calc3() {
	int ans = 0;
	priority_queue<pii, vector<pii>, greater<pii> > x, y, z;
	rep(i, 1, n) {
		if (x.size() >= n / 2) {
			pii X = x.top();
			int val = X.first, id = X.second;
			int sum1 = ans + a[i].a, sum2 = ans + a[i].b;
			if (ans - val + a[i].c + a[id].a > sum1 && ans - val + a[i].c + a[id].b > sum2) {
				int A = ans - val + a[i].c + a[id].a, B = ans - val + a[i].c + a[id].b;
				if (A > B) x.pop(), x.push({a[i].c, i}), y.push({a[id].a, id}), ans += a[id].a + a[i].c - val;
				else x.pop(), x.push({a[i].c, i}), y.push({a[id].b, id}), ans += a[id].b + a[i].c - val;
			}
			else if (ans - val + a[i].c + a[id].a > sum1) x.pop(), x.push({a[i].c, i}), y.push({a[id].a, id}), ans += a[id].a + a[i].c - val;
			else if (ans - val + a[i].c + a[id].b > sum2) x.pop(), x.push({a[i].c, i}), z.push({a[id].b, id}), ans += a[id].b + a[i].c - val;
			else if (sum1 > sum2) y.push({a[i].a, i}), ans += a[i].a;
			else z.push({a[i].b, i}), ans += a[i].b;
		}
		else x.push({a[i].c, i}), ans += a[i].c;
	}
	return ans;
}

int ans = 0;
int maxn[N];

void dfs(int r, int x, int y, int z, int cnt) {
	if (cnt + maxn[r] <= ans) return ;
	if (r == n + 1) {
		ans = max(ans, cnt);
		return ;
	}
	if (x < n / 2) dfs(r + 1, x + 1, y, z, cnt + a[r].a);
	if (y < n / 2) dfs(r + 1, x, y + 1, z, cnt + a[r].b);
	if (z < n / 2) dfs(r + 1, x, y, z + 1, cnt + a[r].c);
}

void solve() {
	ans = 0;
	cin >> n;
	rep(i, 1, n) cin >> a[i].a >> a[i].b >> a[i].c, maxn[i] = max({a[i].a, a[i].b, a[i].c});
	pre(i, n, 1) maxn[i] += maxn[i + 1];
	if (n <= 20) {
		dfs(1, 0, 0, 0, 0);
		cout << ans << '\n';
	}
	else cout << max({calc1(), calc2(), calc3()}) << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	IAKIOI
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
