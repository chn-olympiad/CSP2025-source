#include<bits/stdc++.h>
using namespace std;
int n, m, k;long long res;vector<int> t[10010];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		t[u].push_back(v);t[v].push_back(u);
		res += w;
	}
	printf("%d", res);
	return 0;
}
