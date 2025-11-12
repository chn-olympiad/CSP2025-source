#include <bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
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
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const int N = 15;
int a[N * N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n * m; i++) a[i] = read();
	int ar = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int posr = 0;
	for (int i = 1; i <= n * m; i++) if (a[i] == ar) posr = i;
	int c = (posr + n - 1) / n;
	writech(c, ' ');
	int r = posr % n;
	if (r == 0) r = n;
	writech((c & 1) ? r : n - r + 1, '\n');
	return 0;
}

