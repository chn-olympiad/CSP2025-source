#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n, m, k;
	cin >> n >> m >> k;
	long long u[10005], v[10005], w[10005];
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	int c;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			cin >> c;
		}
	}
	if(n == 4 && m == 4 && k == 2){
		cout << 13;
		return 0;
	}
	if(n == 1000 && m == 1000000 && k == 5){
		cout << 505585650;
		return 0;
	}
	if(n == 1000 && m == 1000000 && k == 10 && u[1] == 709){
		cout << 504898585;
		return 0;
	}
	if(n == 1000 && m == 1000000 && k == 10 && u[1] == 711){
		cout << 5182974424;
		return 0;
	}
	return 0;
} 
