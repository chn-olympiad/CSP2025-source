#include <iostream>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n, k, a[N], s[N], cur;
bool vis[N];
struct node
{
	int ll, rr;
} lr[N];
bool cmp(node x, node y)
{
	return x.ll < y.ll;
}
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (s[i] ^ s[j - 1] == k)
			{
				++cur;
				lr[cur].ll = i, lr[cur].rr = j;
			}
		}
	}
	cout << cur;
	return 0;
}
