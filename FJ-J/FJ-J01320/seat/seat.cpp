#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[200], r;

bool cmp(int x, int y){
	return x > y;
}

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i ++){
		cin >> a[i];
		if(i == 1){
			r = a[i];
		}
	}
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 0;
	for(int i = 1 ; i <= n * m ; i ++){	
		if(x % 2){
			y ++;
		}
		else{
			y --;
		}
		if(a[i] == r){
			cout << x << " " << y << '\n';
			return 0;
		}
		if(x % 2){
			if(y == n){
				x ++ ;
				y = n + 1;
			}
		}
		else{
			if(y == 1){
				x ++ ;
				y = 0;
			}
		}
	}
	return 0;
}

