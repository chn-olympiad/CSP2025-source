#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10, M = 1e6+10;
struct mod{
	int u, v, w;
}a[M];
int b[N], c[N];
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, mon1, mon2;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	cin >> mon1;
	for(int i = 1;i <= n;i++){
		cin >> b[i];
	}
	cin >> mon2;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	
	return 0;
}
