#include <bits/stdc++.h>
using namespace std;
int n, m, pts[105], me, ys = 1, x = 0, y = 1;
bool cmp(int a, int b) { return a > b; }
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> pts[i];
	me = pts[1];
	sort(pts + 1, pts + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(i % n == 1 && i > n) ys = -ys, y++;
		else x += ys;
		if(pts[i] == me){
			cout << y << " " << x;
			return 0;
		}
		
	}
	return 0;
}
