#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, idx;
int a[N], sc;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	//重做水门
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
	sc = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++) if(a[i] == sc) { idx = i; break; }
	int k = idx / n;
	if(idx % n != 0) k++;
	idx = idx - (k - 1) * n;
	if(k % 2 == 1)
	{
		printf("%d %d", k, idx);
	}
	else
	{
		printf("%d %d", k, n + 1 - idx);
	}
	return 0;
}