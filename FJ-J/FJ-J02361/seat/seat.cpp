#include <bits/stdc++.h>
using namespace std;
struct pos {
	int x, y;
} ans;
int n, m, a[105], r, ps;
pos getNextPos(pos p){
	pos res;
	// -1检查
	if (p.y == m){
		if ((m % 2 == 1 && p.x == n) || (m % 2 == 0 && p.x == 1)) {
			res.x = -1;
			res.y = -1;
			return res;
		}
	}
	// 步入正轨
	if (p.y % 2 == 1){
		if (p.x == n){
			res.x = p.x;
			res.y = p.y + 1;
		}
		else{
			res.x = p.x + 1;
			res.y = p.y;
		}
		return res;
	}
	if (p.x == 1){
		res.x = p.x;
		res.y = p.y + 1;
	}
	else{
		res.x = p.x - 1;
		res.y = p.y;
	}
	return res;
}
bool cmp(int lyh, int hsy){
	return lyh > hsy;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort (a+1, a+n*m+1, cmp);
	for (int i=1; i<=n*m; i++){
		if (a[i] == r){
			ps = i;
			break;
		}
	}
	ans.x = 1;
	ans.y = 1;
	for (int i=1; i<ps; i++){
		ans = getNextPos(ans);
	}
	cout << ans.y << " " << ans.x << "\n";
	return 0;
}

