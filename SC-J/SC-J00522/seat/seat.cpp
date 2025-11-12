#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
inline void read(int& x){
	x = 0;
	bool f = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
inline bool cmd(int a , int b){
	return a > b;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;++ i)
	cin >> a[i];
	int s = a[1];
	sort(a + 1 , a + 1 + n * m , cmd);
	int k = 1 , lie = 1 , hang = 0;
	for(int i = 1;i <= n * m;++ i){
		hang += k;
		if(hang > n) k = -1 , hang = n , ++ lie;
		if(!hang) k = 1 , hang = 1 , ++ lie;
		if(s == a[i]){
			cout << lie << ' ' << hang;
			return 0;
		}
	}
	return 0;
}