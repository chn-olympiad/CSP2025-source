#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int ss = 1;
	int my_point = 0;
	cin >> my_point;
	for (int i = 2;i <= n * m; i++){
		int point;
		cin >> point;
		if (point > my_point) ss ++;
	}
	int x = 0, y = 0;
	int pyl = 0;
	if (ss % n != 0){
		y = ss / n + 1;
		pyl = ss - n * (y - 1);
	}
	else {
		y = ss / n;
		pyl = n;
	}
	if (y % 2 == 0){
		x = n - pyl + 1;
	}
	else x = pyl;
	cout << y << " " << x;
	return 0;
}