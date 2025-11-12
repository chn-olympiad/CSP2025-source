#include<bits/stdc++.h>
#define MAXN 10010
#define MAXM 1000010
#define MAXK 15
using namespace std;

int n, m, k;
int c[MAXK];
int a[MAXK][MAXN];
int val[MAXM];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		val[i] = w;
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	sort(val + 1, val + m + 1, cmp);
	long long ans;
	ans = val[1] + val[2];
	printf("%lld\n", ans);
	return 0;
}
