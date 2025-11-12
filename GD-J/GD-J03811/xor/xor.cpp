#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 1e3 + 10;
int n, k, l, r, tot, ans, cnt0 = 0, cnt1 = 0;
int a[N], sum[M][M], dp[N];
struct node
{
	int s, t;
} q[M];
bool cmp(node x, node y)
{
	if(x. s != y. s) return x. s < y. s;
	return x. t < y. t;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if(k <= 1)
	{
		for(int i = 1; i <= n; ++i)
		{
			cnt0 += (a[i] == 0);
			cnt1 += (a[i] == 1);
		}
		if(k == 0) printf("%d", cnt0 + cnt1 / 2);
		else printf("%d", cnt1);
	}
	return 0;
}
