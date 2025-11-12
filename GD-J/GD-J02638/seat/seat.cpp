#include<bits/stdc++.h>
#define long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
int n, m;
int a[114];
bool cmp(int x, int y){
	return x > y;
}
signed main(){
	fin("seat.in");
	fout("seat.out");
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int s = a[1], rs;
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++){
//		cout << a[i] << ' ';
		if(a[i] == s){
			rs = i;
			break;
		}
	}
	int idx = 1, x = 1, y = 1;
	while(idx < rs){
		
		if(x % 2) y++;
		else y--;
		
		if(y == 0) y = 1, x++;
		else if(y == n + 1) y = n, x++;
		idx++;
//		cout << idx << ' ' << x << ' ' << y << '\n';
	}
	cout << x << ' ' << y;
	return 0;
}
/*
2 2
99 100 98 97

3 3
94 95 96 97 98 99 100 93 92
*/

