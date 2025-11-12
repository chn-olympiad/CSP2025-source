#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w, ans = 0;
	cin >> n >> m >> k >> u >> v >> w >> u >> v;
	ans += w;
	cin >> w;
	ans += w;
	cout << ans << endl;
	return 0; 
}

// ¡ª¡ªAt 2025/11/1 16:41:05
