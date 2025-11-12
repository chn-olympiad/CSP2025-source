/*
freeopen freeopen freeopen freeopen freeopen freeopen freeopen freeopen freeopen freeopen freeopen freeopen
*/
#include <bits/stdc++.h>
#define ll long long
#define fi  first
#define se second
using namespace std;
const int N = 1e5 + 10;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9')
	{
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
struct node
{
	int a, b, c;
}a[N];
bool cmp(node a, node b)
{
	int ma = max(a.a, max(a.b, a.c));
	int mb = max(b.a, max(b.b, b.c));
//	if(ma != mb) return ma > mb;
	int na = 0;
	if(ma == a.a) na = max(a.b, a.c);
	else if(ma == a.b) na = max(a.a, a.c);
	else na = max(a.a, a.b);
	int nb = 0;
	if(mb == b.a) nb = max(b.b, b.c);
	else if(mb == b.b) nb = max(b.a, b.c);
	else nb = max(b.a, b.b);
//	cout << ma << " " << na << " " << mb << " " << nb << endl;
	return (ma - na) > (mb - nb);
//	if(na != nb) return na > nb;
//	return (a.a + a.b + a.c - ma - na) > (b.a + b.b + b.c - mb - nb);
}
int p[N][6];
int n;
int num[N][5], top[5], idx[N];
void solve()
{
	n = read();
	for(int i = 1; i <= n; i++)
	{
		int A = read(), b = read(), c = read();
		a[i] = {A, b, c};
	}
	for(int i = 1; i <= 3; i++) top[i] = 0;
//	cout << "sdjsd\n";
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) p[i][1] = a[i].a, p[i][2] = a[i].b, p[i][3] = a[i].c;
//	cout << "SALKSLASKSAKLSKLSA\n";
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
//		cout << p[i][1] << " " << p[i][2] << " " << p[i][3] << endl;
		int mx = 0;
		for(int j = 1; j <= 3; j++) if(mx < p[i][j]) mx = p[i][j], idx[i] = j;
		num[++top[idx[i]]][idx[i]] = i, ans += mx;
	}
	int id = -1;
	for(int i = 1; i <= 3; i++)
	{
		if(top[i] > (n / 2)) id = i;
	}
//	cout << "hihao!!!\n";
	if(id == -1) return printf("%lld\n", ans), void();
	while(top[id] > (n / 2))
	{
		int u = num[top[id]--][id];
//		cout << "!!!   " << id << " " << u << " " << top[id] << " " << p[u][1] << " " << p[u][2] << " " << p[u][3] << endl;
		int nx = 0;
		for(int i = 1; i <= 3; i++)
		{
			if(idx[u] != i) nx = max(nx, p[u][i]);
		}
		ans += (nx - p[u][idx[u]]);
	}
	printf("%lld\n", ans);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
15:07 qwq
*/
