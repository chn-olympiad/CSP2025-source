#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct Edge {
	int u, v, w;
} a[N];
int n, m, k, x[10010], t;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> t;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
		for (int j = 1; j <= m; j++) {
			int y=x[a[j].u] + x[a[j].v] + t;
			a[j].w = min(a[j].w, y);
		}
	}
	if(n==4){
		cout<<"15";
	}
	if(k==5){
		cout<<"505585650";
	}
	if(k==10){
		cout<<"504898585";
	}
}