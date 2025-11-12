#include <bits\stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1000005]
	int h,l;
	cin >> h,l;
	int z = h * l;
	for(int i = 0;i < z;i++){
		int a[i];
		cin >> a[i];
	}
	for(int i = 0;i<z;i++){
		int zj = a[i] > a[i+1];
		if(zj != 1){
			int ccc = a[i];
			a[i] = a[i+1];
			a[i+1] = ccc;
		}
	}
	cout << a << " " << a[i];
	return 0;
}

