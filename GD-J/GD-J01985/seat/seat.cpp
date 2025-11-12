#include <bits/stdc++.h>
using namespace std;
const int maxn = 17 * 17;
int a[maxn];
bool cmp(const int &x, const int &y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int fl = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 0;
	for(int i = 1; i <= n * m; i++){
		if(x & 1) {
			y++;
			if(y > n) x++, y = n;
		}
		else {
			y--;
			if(y < 1) x++, y = 1; 
		}
		if(a[i] == fl) {
			cout << x << " " << y << endl;
			return 0;
		}
	}
	return 0;
}
