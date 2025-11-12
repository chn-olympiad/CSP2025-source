#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int n, m, y = 1, R, Rx;
int a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	R = a[1];
	sort(a + 1, a + n * m + 1, cmp);//down
	for(int i = 1; i <= n * m; i++)
		if(R == a[i])
			Rx = i;
	y += (Rx - 1) / n;//可能要Rx特殊处理 
	Rx -= (y - 1) * n;
	if(y % 2 == 1)
		cout << y << ' ' << Rx;
	else
		cout << y << ' ' << n - Rx + 1;
	return 0;
} 
