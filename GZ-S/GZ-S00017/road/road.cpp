//GZ-S00017 贵阳市第一中学 伍星恒 
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> u, v;
int x, y;
int w[200000001];
int c[10], a[10][10001];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> w[i];
		u.push_back(x);
		v.push_back(y);
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	
	sort(w+1, w+m+1);
	int ans = 0;
	for(int i = 1; i < n; i++){
		ans += w[i];
	}
	cout << ans << endl;
	return 0;
}
