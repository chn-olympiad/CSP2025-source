#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int u[N];
int v[N];
int w[N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int a, b;
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> u[i] >> v[i] >> w[i];
		sum += w[i];
	}
	cout << sum;
} 


