#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], ans[15][15];
int c, r;
bool cmp(int w, int t){
	return w > t;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int ming = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1;
	for(int i = 1; i <= n * m; i++){
		ans[x][y] = a[i];
		
		if(ans[x][y] == ming){
			cout << y << " " << x;
			return 0;
		}
		if(y % 2 != 0){
			if(x == n){
				y++;
			}
			else{
				x++;
			}
		}
		else{
			if(x == 1){
				y++;
			}
			else{
				x--;
			}
		}
	}
	return 0;
}

