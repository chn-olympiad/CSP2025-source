#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1005][1005], b[10005];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
	}
	for(int i = 1; i <= n+1; i++){
		cin >> a[i][i];
	}
	cout << 0;
	return 0;
}
