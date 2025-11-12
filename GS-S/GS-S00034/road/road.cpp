#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, sum = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int w, v, u;
		cin >> w >> v >> u;
		sum += w+v+u;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
