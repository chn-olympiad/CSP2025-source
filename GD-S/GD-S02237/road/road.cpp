#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 1000005;
int n, m, k;
struct node{
	int u, v, w;
}c[M];
bool cmp(node x, node y){
	return x.w < y.w;
}
int d[15], a[15][N];
bool flag;
int f[N];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++){
		cin >> c[i].u >> c[i].v >> c[i].w;
	}
	for (int i=1; i<=k; i++){
		cin >> d[i];
		if (d[i]!=0) flag = true;
		for (int j=1; j<=n; j++){
			cin >> a[i][j];
			if (a[i][j]!=0) flag = true;
		}
	}
	if (flag==false && k!=0){
		cout << 0;
		return 0;
	}
	if (k==0){
		sort(c+1, c+m+1, cmp);
		long long ans;
		ans += c[1].w;
		f[c[1].u] = 1;
		f[c[1].v] = 1;
		int sum = 1;
		for (int i=2; i<=m; i++){
			if (f[c[i].u]==0 && f[c[i].v]==0){
				f[c[i].u] = sum+1;
				f[c[i].v] = sum+1;
				sum ++;
				ans += c[i].w;
			} else if (f[c[i].u]==0){
				f[c[i].u] = f[c[i].v];
				ans += c[i].w;
			} else if (f[c[i].v]==0){
				f[c[i].v] = f[c[i].u];
				ans += c[i].w;
			} else if (f[c[i].u]!=f[c[i].v]){
				for (int j=1; j<=n; j++){
					if (f[j]==f[c[i].v]) f[j] = f[c[i].u];
				}
				ans += c[i].w;
			}
		}
		cout << ans;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
