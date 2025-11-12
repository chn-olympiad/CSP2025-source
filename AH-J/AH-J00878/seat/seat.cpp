#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n , m , a[101][101] , b[10001] , tt = 0;
bool cmp(LL x , LL y){
	if(x > y) return true;
	else return false;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(LL i = 1 ; i <= n ; i++){
		for(LL j = 1 ; j <= m ; j++){
			cin >> a[i][j];
			b[i * m - m + j] = a[i][j];	
		}
	}
	sort(b + 1 , b + 1 + (n * m) , cmp);
	for(LL i = 1 ; i <= n * m ; i++) if(a[1][1] == b[i]) tt = i;
	LL yy = (tt - 1) / n + 1;
	if(yy % 2 == 0) cout << yy << ' ' << n - (tt - 1) % n;
	else cout << yy << ' ' << (tt - 1) % n + 1;
	return 0;
}
