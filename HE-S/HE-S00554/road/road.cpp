#include <bits/stdc++.h>
using namespace std;
int a[1111111], b[1111111], c[1111111], d[1111111] = {0};
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	int a1, a2, a3, a4, a5;
	for(int i = 1; i <= k; i++){
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
	}
	for(int i= 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(c[j] > c[j+1]){
				swap(a[j], a[j+1]);
				swap(b[j], b[j+1]);
				swap(c[j], c[j+1]);
			}
		}
	}
	int ans = 0, p = 0;
	for(int i=1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(d[j] > 0){
				p++;
			}
		}
		if(p == m){
			break;
		}
		ans += c[i];
		d[a[i]]++;
		d[b[i]]++;
	}
	cout << ans;
	return 0;
}
