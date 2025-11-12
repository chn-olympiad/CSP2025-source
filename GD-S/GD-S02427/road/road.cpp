#include <bits/stdc++.h>
using namespace std;
struct node{
	int u, v, w;
}a[5000005];
queue<node> q;
int n, m, k, sum, ans, c[500005], p[500005][10005], pn[10005], pm[10005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		a[i].u = u;
		a[i].v = v;
		a[i].w = w;
		ans += w;
	}
	for(int i = 0; i < k; i++){
		cin >> c[i];
		pn[i] += c[i];
		for(int j = 0; j < n; j++){
			cin >> p[i][j];
			pn[i] += p[i][j];
			pm[i] = max(p[i][j], pm[i]);
		}
	}
	for(int i = 0 ;i < n; i++){
		if(pn[i] > ans){
			for(int j = 0; j < m; j++){
				if(a[j].u == i)
					sum = max(a[j].w, sum);
				if(a[j].v == i)
					sum = max(a[j].w, sum);
			}
			if(pn[i] - pm[i] < ans - sum){
				cout<<pn[i]+sum;
			}
			else
				cout << ans;
		}
	}
	return 0;
}
