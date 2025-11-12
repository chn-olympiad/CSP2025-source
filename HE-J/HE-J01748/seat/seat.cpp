#include <bits/stdc++.h>
using namespace std;
struct asd{
	int cj , bh;
}a[110];
bool cmp (asd x , asd y){
	if(x.cj == y.cj) return x.bh < y.bh;
	return x.cj > y.cj;
}
signed main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m; 
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++){
		cin >> a[i].cj;
		a[i].bh = i;
	} 
	sort(a+1 , a+1+(n*m) , cmp);
	for(int i = 1 ; i <= n * m ; i++){
		if(a[i].bh == 1){
			if(i % n == 0){
				cout << ceil(i * 1.0 / n * 1.0) << " " << n;
			}else{
				cout << ceil(i * 1.0 / n * 1.0) << " " << i % n;
			}
			return 0;
		}
	}
	return 0;
}
