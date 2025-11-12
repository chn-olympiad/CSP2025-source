#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 505;
const LL MOD = 998244353;

int n, m; 
int s[N], c[N];

bool A = true;
int B;

LL res;

bool vis[N];
int tmp[N];
void DFS(int idx)
{
	if (idx > n)
	{
		int t = 0, cnt = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if (t >= tmp[i]) t ++ ;
			else if (s[i]) cnt ++ ;
			else t ++ ;
		}
		if (cnt >= m) res = (res + 1) % MOD;
	}
	
	for (int i = 1; i <= n; i ++ )
		if (!vis[i])
		{
			tmp[idx] = c[i];
			vis[i] = true;
			DFS(idx + 1);
			vis[i] = false;
		}
}

int b[N], idx;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) 
	{
		scanf("%1d", &s[i]);
		if (!s[i]) A = false;
		B += s[i];
	}
	for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
	
	if (n <= 10)
	{
		DFS(1);
		printf("%lld\n", res);
	}
	else if (A) 
		puts("0");

	return 0;
}


