#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int n , m , d , sum , mid , a[N] , b[N];
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.oout" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m; i++) cin >> a[i];
	int r = a[1];
	sort(a + 1 , a + n * m + 1);
	for(int i = 1 ; i <= n * m ; i++){
		if(r == a[i]){
			d = i;
			break;
		}
	}
	sum = n * m - d + 1;
	if(sum <= n){
		cout << 1 << " ";
		if(sum % n == 0) cout << n << endl;
		else cout << sum % n << endl;
	}
	else{
		if(sum % n == 0){
			if(sum % 2 == 0){
				cout << sum / n << " " << 1 << endl;
			}
			else{
				cout << sum / n << " " << n << endl;
			}
		}
		else{
			if((sum / n + 1) % 2 == 0){
				cout << sum / n + 1 << " ";
				cout << n - (sum % n) + 1 << endl;
			}
			else{
				cout << sum / n + 1 << " ";
				cout << sum % n << endl;
			}
		}
	}
	return 0;
}
//94 92 93 95 96 97 98 99 100
