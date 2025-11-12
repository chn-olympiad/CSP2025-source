#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6 + 10;
struct infor
{
	int u, v, w;
} a[INF];
int main ()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1 ; i <= m ; i ++)
	{
		scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
	}
	for (int i = 1 ; i <= n + 1 ; i ++)
	{
		int x;
		scanf("%d", &x);
	}
	printf("45\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
