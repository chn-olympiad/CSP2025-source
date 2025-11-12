#include <bits/stdc++.h>
using namespace std;
long long n , m , q , cnt[5000005] , ans;
int main(){
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i ++){
		int u , v , w;
		cin >> u >> v >> w;
		cnt[i] = w;
	}
	int k = m;
	for (int i = 1; i <= q; i ++){
		int a , b , c;
		cin >> a >> b;
		for (int j = 1; j < n; j ++){
			cin >> c;
			k ++;
			cnt[k] = a + b + c;
		}
	}
	sort (cnt + 1 , cnt + 1 + k);
	for (int i = 1; i < n; i ++) ans += cnt[i];
	cout << ans;
	return 0;
}
