#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[50010][4], mm, mn[4], mans, ans, mx, total;
void bfs(ll f, ll total){
	if(f > n){
		if(ans > mans) {
			mans = ans;
		}
		return;
	}
	if(ans + total <= mans) return;
	for(int j = 1; j <= 3; j++){
		if(mn[j] >= mm) continue;
		mn[j]++;
		ans += a[f][j];
		bfs(f + 1, total - a[f][0]);
		mn[j]--;
		ans -= a[f][j];
	}
	return;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t;
	cin >> t;
	while(t--){
		mans = 0;
		ans = 0;
		mx = 0;
		total = 0;
		mn[1] = mn[2] = mn[3] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				a[i][0] = max(a[i][1], max(a[i][2], a[i][3]));
			}
			total += a[i][0];
		}
		mm = n / 2;
		bfs(1, total);
		cout << mans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
