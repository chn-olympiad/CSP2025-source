#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[1000],numr,p,c,r;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	numr = a[1];
	sort(a+1,a+n*m+1);
	
	for(int i = 1;i <= n*m;i++){
		if(a[i] == numr){
			p = n*m+1-i;
			break;
		}
	}
	c = p/n+1;
	if(p%n != 0){
		if(c%2 == 0){
			r = p%n;
			r = n+1-r;
		}
		if(c%2 == 1){
			r = p%n;
		}
	}
	else{
		c--;
		if(c%2 == 0){
			r=1;
		}
		if(c%2 == 1){
			r = n;
		}
	}
	cout << c << " " << r;
	return 0;
}
