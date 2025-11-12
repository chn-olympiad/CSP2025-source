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
const int N = 5e5 + 5, A = (1 << 20) + 5;
int a[N], lst[A], sum[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read(), sum[i] = (sum[i - 1] ^ a[i]);
	memset(lst, -1, sizeof(lst));
	int ans = 0, pos = 0;
	lst[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (lst[sum[i] ^ k] + 1 > pos)
		{
			ans++;
			pos = i;
		}
		lst[sum[i]] = i;
	}
	write(ans);
	return 0;
}

