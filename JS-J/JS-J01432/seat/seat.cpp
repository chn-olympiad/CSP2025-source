#include <bits/stdc++.h>
using namespace std;

int n, m, a[110], ans, x = 1, y = 1, t = 1;
bool flag = true;

bool cmp(const int x1, const int y1){
	return x1 > y1;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	ans = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	while(a[t] != ans){
		if(flag){
			if(x == n){
				flag = false;
				y++;
			}else{
				x++;
			}
		}else{
			if(x == 1){
				flag = true;
				y++;
			}else{
				x--;
			}
		}
		t++;
	}
	cout << y << ' ' << x << endl;
	return 0;
}
