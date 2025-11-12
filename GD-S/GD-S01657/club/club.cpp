#include <bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
#define md make_pair
#define gc getchar
#define pc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll res = 0, f = 1; char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = gc();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = gc();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const int N = 1e5 + 5;
int a[N][4];
int cnt[4];
struct node {
	int d, i, id1, id2;
} b[N];
bool cmp(node x, node y) { return x.d != y.d ? x.d > y.d : a[x.i][x.id1] > a[y.i][y.id1]; }
void solve()
{
	memset(cnt, 0, sizeof(cnt));
	int n = read();
	for (int i = 1; i <= n; i++) for (int j = 1; j <= 3; j++) a[i][j] = read();
	for (int i = 1; i <= n; i++)
	{
		int mxid1 = 0;
		for (int j = 1; j <= 3; j++) if (a[i][j] > a[i][mxid1]) mxid1 = j;
		int mxid2 = 0;
		for (int j = 1; j <= 3; j++) if (j != mxid1 && a[i][j] > a[i][mxid2]) mxid2 = j;
		b[i] = {a[i][mxid1] - a[i][mxid2], i, mxid1, mxid2};
	}
	sort(b + 1, b + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int id1 = b[i].id1, id2 = b[i].id2;
		if (cnt[id1] < n / 2) ans += a[b[i].i][id1], cnt[id1]++;
		else if (cnt[id2] < n / 2) ans += a[b[i].i][id2], cnt[id2]++;
		else ans += a[b[i].i][6 - id1 - id2], cnt[6 - id1 - id2]++;
	}
	writech(ans, '\n');
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T--) solve();
	return 0;
}

