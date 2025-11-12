#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		int u , v , w;
		cin >> u >> v >> w;
	}
	int ans = INT_MAX;
	for(int i = 1;i <= k;i ++){
		int sum = 0;
		for(int j = 1;j <= n + 1;j ++){
			int t;
			cin >> t;
			sum += t;
		}
		ans = min(ans , sum);
	}
	cout << ans;
	return 0;
} 
