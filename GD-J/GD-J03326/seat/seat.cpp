#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int zw[N][N];
int a[N + 100];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++){
		cin >> a[i];//buchu
	}
	int flag = a[1];
	sort(a + 1 ,a + 1 + n * m, cmp);
	int cg;
	for(int i = 1 ; i <= n * m ; i++){
		if(a[i] == flag){
			cg = i;
			break;
		}
	}
//	if(n == 1){
//		cout << 1 << " " << cg;
//		return 0;
//	}
//	else if(m == 1){
//		cout << cg << " " << 1;
//		return 0;
//	}
	int x = 1 , y = 1 , k = 1;
	//cout << " cg = " << cg << endl;
	while(true){
		//cout << "x = " << x << " y = " << y << " k = " << k <<'\n' ;
		if(k == cg){
			cout << x << " " << y;
			return 0;
		}
		k++;
		if(x % 2 == 1 && y != n)y++;
		else if(x % 2 == 0 && y != 1)y--;
		else if(x % 2 == 1 && (x != m && y == n))x ++;
		else if(x % 2 == 0 && (x != m && y == 1))x++;
	}
	//不满分不活了 
	return 0;
}
