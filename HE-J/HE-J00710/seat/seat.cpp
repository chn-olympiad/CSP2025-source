#include <iostream>
#include <algorithm>
using namespace std;
int n,m,c,k = 1;
int ste[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n*m;i++){
		cin >> ste[i];
	}
	c = ste[1];
	if (n == 1&&m == 1){
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	for (int i = 2;i<=n*m;i++){
		if (c < ste[i])k++;
	}
	if (k % n == 0){
		if (k%(2*n)==0){
			cout << k/n << " " << n;
		}else{
			cout << k/n << " " << n;
		}
		return 0;
	}
	if (k%(2*n)<n){
		cout << k/n+1 << " " << k%n << endl ;
		
	}else{
		cout << k/n+1 << " " << n-k%n+1 << endl;
		
	}
	return 0;
}
