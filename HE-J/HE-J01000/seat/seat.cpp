#include<bits/stdc++.h>

using namespace std;

int n , m , a[1010] , b[1010];

int main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++) cin >> a[i];
	int cnt = a[1] , res = 0;
	sort(a + 1 , a + n*m + 1);
	reverse(a + 1 , a + n*m + 1);
	for(int i = 1;i <= n * m;i ++){
		if(a[i] == cnt)	{
			res = i;
			break;
		}
	}
//	cout << "*" << res;
	for(int i = 1 ,j = n;i <= n,j >= 1;i ++,j --)	b[i] = j;
//	for(int res = 1;res <= n*m;res ++){
	int y = res % n , x;
	if(y == 0)	x = res/n;
	else x = res/n + 1; 
	if(x%2 == 1){
		cout << x << " " << (y == 0?n:y);
	}	
	else cout << x << " " << (y == 0?1:b[y]);
//	}
		 
	return 0;
}
/*
3 6
5 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18
*/
