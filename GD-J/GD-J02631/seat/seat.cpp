#include<bits/stdc++.h>
using namespace std;

int cnt;
int n, m, a0;

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	cin >> a0;
	int atmp;
	for(int i=1;i<n*m;i++){
		cin >> atmp;
		if(atmp>a0) cnt++;
	}
//	cout << cnt;
	int x = cnt%n; // 这一列的第 x 个 
//	printf("cnt=%d, n=%d, cnt mod n=%d\n", cnt, n, x);
	int y = cnt/n+1; // 第 y 列
	cout << y << ' ';
	if(y%2==0){ // 偶列，自下而上 
		cout << (n-x);
	} else { // 奇列，自上而下 
		cout << (x+1);
	}
	
	return 0;
}
