#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;
	int v;
	long long w;
}a[1000005];
int f[10005];
long long sum;
int b[15][10005]; 
bool cmp(node a, node b){
	return a.w < b.w; 
}
int find(int x){
	if (f[x] == x)return x;
	else{
		return f[x] = find(f[x]);
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		f[i] = i;
	}
	for (int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= n; j++){
			cin >> b[i][j];
		}
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++){
		int xx = find(a[i].u);
		int yy = find(a[i].v);
		if (xx == yy)continue;
		f[a[i].v] = f[a[i].u];
		sum += a[i].w;
	}
	cout << sum;
	return 0;
} 
