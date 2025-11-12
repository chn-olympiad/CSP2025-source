#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int fa[10100];
int get(int x){
	if (fa[x] == x)return x;
	return fa[x] = get(fa[x]);
}
struct edge{
	int u;
	int v;
	long long a;
	bool operator < (edge &o){
		return a < o.a;
	}
}e[1000010];
long long newc[20][10010];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		cin >> e[i].u >> e[i].v >> e[i].a;
	}
	sort(e, e + m);
	for (int i = 1; i <= n; i++)fa[i] = i;
	int cnt = n - 1;
	long long sum = 0;
	for (int i = 0; i < m; i++){
		int a = get(e[i].u);
		int b = get(e[i].v);
		fa[a] = b;
		if (a != b)cnt--, sum += e[i].a;
	}
	cout << sum;
	return 0;
} 
