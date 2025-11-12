#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cnt, num = 1;
	cin >> n >> m >> cnt;
	for(int i = 1, x;i < n*m;i++){
		cin >> x;
		if(x > cnt) num++;
	}int c = num/n+(num%n == 0?0:1), r;
	if(c%2 == 1) r = num-(c-1)*n;
	else if(c%2 == 0) r = n-(num-(c-1)*n)+1;
	cout << c << " " << r << endl;
	return 0; 
}
