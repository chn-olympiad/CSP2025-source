#include<bits/stdc++.h>
using namespace std;
int n , m , a[105] , p = 0 , q = 0 , c = 0 , r = 0;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)cin >> a[i];
	p = a[1];
	sort(a + 1 , a + n * m + 1);
	for(int i = 1; i <= n * m; i ++){
		if(a[i] == p){
			q = n * m - i + 1;
			break;
		}
	}
	if(q % n)c ++;
	c += (q / n);
	if(q % (2 * n) >= 1 && q % (2 * n) <= n){
		if(q % n == 0)r = n;
		else r = q % n;
	}
	else{
		if(q % n == 0)r = 1;
		else r = n - q % n + 1;
	}
	cout << c << " " << r;
	return 0;
}