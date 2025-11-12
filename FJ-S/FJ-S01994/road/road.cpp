#include<bits/stdc++.h>
using namespace std;
int n, m, k, res;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int tmp;
	for(int i = 1; i <= n; i ++){
		cin >> tmp >> tmp >> tmp;
		res += tmp;
	}
	for(int i = 1; i <= k; i ++){
		for(int j = 0; j <= n; j ++){
			cin >> tmp;
		}
	}
	cout << res;
	return 0;
}
